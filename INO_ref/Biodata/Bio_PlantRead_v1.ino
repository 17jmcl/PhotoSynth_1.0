#include <EEPROMex.h> //store and read variables to nonvolitle memory
#include <Bounce2.h> //https://github.com/thomasfredericks/Bounce-Arduino-Wiring

//Code based on MidiSprout, needs major updates 

//******************************
// Note: Change once tested for aesthetic purposes, make into function scaleValeus  
//set scaled values, sorted array, first element scale length
const int scaleCount = 5;
const int scaleLen = 13; //maximum scale length plus 1 for 'used length'
int currScale = 0; //current scale, default Chrom
int scale[scaleCount][scaleLen] = {
  {12,1,2,3,4,5,6,7,8,9,10,11,12}, //Chromatic
  {7,1, 3, 5, 6, 8, 10, 12}, //Major
  {7,1, 3, 4, 6, 8, 9, 11}, //DiaMinor
  {7,1, 2, 2, 5, 6, 9, 11}, //Indian
  {7,1, 3, 4, 6, 8, 9, 11} //Minor
};

int root = 0; //initialize for root, pitch shifting
//*******************************
// Note: Make .h file for various initializations for organization purposes 
const byte interruptPin = 5; //galvanometer input
int pulseRate = 350; //base pulse rate

const byte samplesize = 10; //set sample array size
const byte analysize = samplesize - 1;  //trim for analysis array

// I think it will be mono but may change 
const byte polyphony = 1; //above 8 notes may run out of ram
int channel = 12;  //setting channel to 11 or 12 often helps simply computer midi routing setups
int noteMin = 36; //C2  - keyboard note minimum
int noteMax = 96; //C7  - keyboard note maximum
byte QY8= 0;  //sends each note out chan 1-4, for use with General MIDI like Yamaha QY8 sequencer
byte controlNumber = 80; //set to mappable control, low values may interfere with other soft synth controls!!
byte controlVoltage = 1; //output PWM CV on controlLED, pin 17, PB3, digital 11 *lowpass filter

byte timeout = 0;
int value = 0;
int prevValue = 0;

volatile unsigned long microseconds; //sampling timer
volatile byte index2 = 0;
volatile unsigned long samples[samplesize];

float threshold = 1.7;   //2.3;  //change threshold multiplier
float threshMin = 1.61; //scaling threshold min
float threshMax = 3.71; //scaling threshold max

unsigned long previousMillis = 0;
unsigned long currentMillis = 1;
unsigned long batteryCheck = 0; //battery check delay timer

typedef struct _MIDImessage { //build structure for Note and Control MIDImessages
  unsigned int type;
  int value;
  int velocity;
  long duration;
  long period;
  int channel;
} 

MIDImessage;
MIDImessage noteArray[polyphony]; //manage MIDImessage data as an array with size polyphony
int noteIndex = 0;
MIDImessage controlMessage; //manage MIDImessage data for Control Message (CV out)


void setup()
{
  randomSeed(analogRead(0)); //seed for QY8 4 channel mode
  Serial.begin(31250);  //initialize at MIDI rate
  //Serial.begin(9600); //for debugging 
  
  controlMessage.value = 0;  //begin CV at 0
  //MIDIpanic(); //dont panic, unless you are sure it is nessisary
  attachInterrupt(interruptPin, sample, RISING);  //begin sampling from interrupt
  
}

void loop()
{
  currentMillis = millis();   //manage time
  //checkBattery(); //on low power, shutoff lightShow, continue MIDI operation
  if(index2 >= samplesize)  { analyzeSample(); }  //if samples array full, also checked in analyzeSample(), call sample analysis   
  checkNote();  //turn off expired notes 
  checkControl();  //update control value
  delay(100);
  Serial.println(interruptPin);
}




void setNote(int value, int velocity, long duration, int notechannel)
{
  //find available note in array (velocity = 0);
  for(int i=0;i<polyphony;i++){
    if(!noteArray[i].velocity){
      //if velocity is 0, replace note in array
      noteArray[i].type = 0;
      noteArray[i].value = value;
      noteArray[i].velocity = velocity;
      noteArray[i].duration = currentMillis + duration;
      noteArray[i].channel = notechannel;
        if(QY8) { midiSerial(144, notechannel, value, velocity); } 
        else { midiSerial(144, channel, value, velocity); }
      break;
    }
  }
}

void setControl(int type, int value, int velocity, long duration)
{
  controlMessage.type = type;
  controlMessage.value = value;
  controlMessage.velocity = velocity;
  controlMessage.period = duration;
  controlMessage.duration = currentMillis + duration; //schedule for update cycle
}


void checkControl()
{
  //need to make this a smooth slide transition, using high precision 
  //distance is current minus goal
  signed int distance =  controlMessage.velocity - controlMessage.value; 
  //if still sliding
  if(distance != 0) {
    //check timing
    if(currentMillis>controlMessage.duration) { //and duration expired
        controlMessage.duration = currentMillis + controlMessage.period; //extend duration
        //update value
       if(distance > 0) { controlMessage.value += 1; } else { controlMessage.value -=1; }
       
       //send MIDI control message after ramp duration expires, on each increment
       midiSerial(176, channel, controlMessage.type, controlMessage.value); 
    }
  }
}

void checkNote()
{
  for (int i = 0;i<polyphony;i++) {
    if(noteArray[i].velocity) {
      if (noteArray[i].duration <= currentMillis) {
        //send noteOff for all notes with expired duration    
          if(QY8) { midiSerial(144, noteArray[i].channel, noteArray[i].value, 0); }
          else { midiSerial(144, channel, noteArray[i].value, 0); }
        noteArray[i].velocity = 0;
      }
    }
  }

}

void MIDIpanic()
{
  //120 - all sound off
  //123 - All Notes off
 // midiSerial(21, panicChannel, 123, 0); //123 kill all notes
  
  //brute force all notes Off
  for(byte i=1;i<128;i++) {
    delay(1); //don't choke on note offs!
    midiSerial(144, channel, i, 0); //clear notes on main channel

       if(QY8){ //clear on all four channels
         for(byte k=1;k<5;k++) {
          delay(1); //don't choke on note offs!
          midiSerial(144, k, i, 0);
         }
       } 
  }
  
  
}

void midiSerial(int type, int channel, int data1, int data2) {

  cli(); //kill interrupts, probably unnessisary
    //  Note type = 144
    //  Control type = 176  
    // remove MSBs on data
    data1 &= 0x7F;  //number
    data2 &= 0x7F;  //velocity
    
    byte statusbyte = (type | ((channel-1) & 0x0F));
    
    Serial.write(statusbyte);
    Serial.write(data1);
    Serial.write(data2);
  sei(); //enable interrupts
}



/*
long readVcc() {  //https://code.google.com/p/tinkerit/wiki/SecretVoltmeter
  long result;
  // Read 1.1V reference against AVcc
  ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
  delay(2); // Wait for Vref to settle
  ADCSRA |= _BV(ADSC); // Convert
  while (bit_is_set(ADCSRA,ADSC));
  result = ADCL;
  result |= ADCH<<8;
  result = 1126400L / result; // Back-calculate AVcc in mV
  return result;
}

void checkBattery(){
  //check battery voltage against internal 1.1v reference
  //if below the minimum value, turn off the light show to save power
  //don't check on every loop, settle delay in readVcc() slows things down a bit
 if(batteryCheck < currentMillis){
  batteryCheck = currentMillis+10000; //reset for next battery check
   
  if(readVcc() < batteryLimit) {   //if voltage > valueV
    //battery failure  
    if(checkBat) { //first battery failure
      for(byte j=0;j<LED_NUM;j++) { leds[j].stop_fade(); leds[j].set_value(0); }  //reset leds, power savings
      noteLEDs = 0;  //shut off lightshow set at noteOn event, power savings
      checkBat = 0; //update, first battery failure identified
    } else { //not first low battery cycle
      //do nothing, lights off indicates low battery
      //MIDI continues to flow, MIDI data eventually garbles at very low voltages
      //some USB-MIDI interfaces may crash due to garbled data
    } 
  } 
 }
}
*/


//provide float map function
float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

//debug SRAM memory size
int freeRAM() {
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
} // print free RAM at any point


void thresholdMode() {
  int runMode = 1;
  while(runMode) {
    //float knobValue 
    threshold = 50;
    //set threshold to knobValue mapping
    threshold = mapfloat(threshold, 5, 100, threshMin, threshMax);  
    
    if(index2 >= samplesize)  { analyzeSample(); }  //keep samples running
    checkNote();  //turn off expired notes 
    checkControl();  //update control value
    
    currentMillis = millis();
  }  //after button press retain threshold setting
}


void scaleMode() {
  int runMode = 1;
  int prevScale = 0;
  while(runMode) {
    currScale = 10;  
    //set current Scale choice
    currScale = map(currScale, 5, 100, 0, scaleCount);
 
    if(index2 >= samplesize)  { analyzeSample(); }  //keep samples running
    checkNote();  //turn off expired notes 
    checkControl();  //update control value
    
    currentMillis = millis();
  }  //after button press retain threshold setting

  
}

void channelMode() {
  int runMode = 1;
  while(runMode) {
    channel = 12;  
    //set current MIDI Channel between 1 and 16
    channel = map(channel, 5, 100, 1, 17);
    

    if(index2 >= samplesize)  { analyzeSample(); }  //keep samples running
    checkNote();  //turn off expired notes 
    checkControl();  //update control value
    
    currentMillis = millis();
  }  //after button press retain threshold setting

}


//interrupt timing sample array
void sample()
{
  if(index2 < samplesize) {
    samples[index2] = micros() - microseconds;
    microseconds = samples[index2] + microseconds; //rebuild micros() value w/o recalling
    //micros() is very slow
    //try a higher precision counter
    //samples[index] = ((timer0_overflow_count << 8) + TCNT0) - microseconds;
    index2 += 1;
  }
}



void analyzeSample()
{
  //eating up memory, one long at a time!
  unsigned long averg = 0;
  unsigned long maxim = 0;
  unsigned long minim = 100000;
  float stdevi = 0;
  unsigned long delta = 0;
  byte change = 0;

  if (index2 == samplesize) { //array is full
    unsigned long sampanalysis[analysize];
    for (byte i=0; i<analysize; i++){ 
      //skip first element in the array
      sampanalysis[i] = samples[i+1];  //load analysis table (due to volitle)
      //manual calculation
      if(sampanalysis[i] > maxim) { maxim = sampanalysis[i]; }
      if(sampanalysis[i] < minim) { minim = sampanalysis[i]; }
      averg += sampanalysis[i];
      stdevi += sampanalysis[i] * sampanalysis[i];  //prep stdevi
    }

    //manual calculation
    averg = averg/analysize;
    stdevi = sqrt(stdevi / analysize - averg * averg); //calculate stdevu
    if (stdevi < 1) { stdevi = 1.0; } //min stdevi of 1
    delta = maxim - minim; 
    
    //**********perform change detection 
    if (delta > (stdevi * threshold)){
      change = 1;
    }
    //*********
    
    if(change){// set note and control vector
       int dur = 150+(map(delta%127,1,127,100,2500)); //length of note
       int ramp = 3 + (dur%100) ; //control slide rate, min 25 (or 3 ;)
       int notechannel = random(1,5); //gather a random channel for QY8 mode
       
       //set scaling, root key, note
       int setnote = map(averg%127,1,127,noteMin,noteMax);  //derive note, min and max note
       setnote = scaleNote(setnote, scale[currScale], root);  //scale the note
       // setnote = setnote + root; // (apply root?)
       if(QY8) { setNote(setnote, 100, dur, notechannel); } //set for QY8 mode
       else { setNote(setnote, 100, dur, channel); }
  
       //derive control parameters and set    
       setControl(controlNumber, controlMessage.value, delta%127, ramp); //set the ramp rate for the control
     }
     //reset array for next sample
    index2 = 0;
  }
}


int scaleSearch(int note, int scale[], int scalesize) {
 for(byte i=1;i<scalesize;i++) {
  if(note == scale[i]) { return note; }
  else { if(note < scale[i]) { return scale[i]; } } //highest scale value less than or equal to note
  //otherwise continue search
 }
 //didn't find note and didn't pass note value, uh oh!
 return 6;//give arbitrary value rather than fail
}


int scaleNote(int note, int scale[], int root) {
  //input note mod 12 for scaling, note/12 octave
  //search array for nearest note, return scaled*octave
  int scaled = note%12;
  int octave = note/12;
  int scalesize = (scale[0]);
  //search entire array and return closest scaled note
  scaled = scaleSearch(scaled, scale, scalesize);
  scaled = (scaled + (12 * octave)) + root; //apply octave and root
  return scaled;
}
