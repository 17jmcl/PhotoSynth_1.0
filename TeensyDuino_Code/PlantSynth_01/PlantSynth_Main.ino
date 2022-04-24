

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
(!Serial);
AudioMemory(20);


//setup sgtl5000_1
sgtl5000_1.enable();
sgtl5000_1.volume(0.5);

//setup main mixers 
mixer3.gain(0,0.9);
waveformMod1.amplitude(0.7);

//setup Piano
PlantSynthPiano newpiano;
newpiano.pianoSetup();

PlantSynthPlant newplant; 
newplant.plantSetup();

PlantSynthKnob newknob; 
newknob.knobSetup(10);

//bitcrush effect setup 
mixer1.gain(0,0.0); 
mixer3.gain(1,0.0); 
button1.attach( BUTTON_PIN2, INPUT );
button1.interval(5); 
button1.setPressedState(LOW); 
pinMode(LED_PIN2,OUTPUT);
digitalWrite(LED_PIN2,ledState);
attachInterrupt((digitalPinToInterrupt(BUTTON_PIN2)), buttonpress, CHANGE);

}

void loop() {

//Piano
playKey();
//Plant Mod (Shape Mod) 
modWave();

//bitcrush effect 
button1.update();
buttonpress();
updatebitcrush();

}
