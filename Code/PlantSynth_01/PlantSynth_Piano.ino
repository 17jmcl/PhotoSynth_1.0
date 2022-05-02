#include "Arduino.h" 
#include "PlantSynth_Piano.h"
#include "PlantSynth_AstableMultivibrator.h"

// setup piano sensors 
void PlantSynthPiano::pianoSetup(){
mixGainSetup();
setPianoHz(); 
}

// instantiate all piano key mixer gains to 0.3 
void PlantSynthPiano::mixGainSetup(){
for (int i=0; i<4; i++){
mixer10.gain(i,0.3);
mixer8.gain(i,0.3);
mixer9.gain(i,0.3);
mixer11.gain(i,0.3);
}
};

//set piano keys by Hz 
void PlantSynthPiano::setPianoHz(){
waveformMod1.begin(0.0,493.88,WAVEFORM_PULSE);

waveformMod2.begin(0.0,261.63,WAVEFORM_PULSE);

waveformMod3.begin(0.0,277.18,WAVEFORM_PULSE);

waveformMod4.begin(0.0,293.66,WAVEFORM_PULSE);

waveformMod5.begin(0.0,311.13,WAVEFORM_PULSE);

waveformMod6.begin(0.0,329.63,WAVEFORM_PULSE);

waveformMod7.begin(0.0,349.23,WAVEFORM_PULSE);

waveformMod8.begin(0.0,369.99,WAVEFORM_PULSE);

waveformMod9.begin(0.0,392.00,WAVEFORM_PULSE);

waveformMod10.begin(0.0,415.30,WAVEFORM_PULSE);

waveformMod11.begin(0.0,440,WAVEFORM_PULSE);

waveformMod12.begin(0.0,466.16,WAVEFORM_PULSE);
};

int currWave(){
int knobVal = analogRead(A18);
if (knobVal <= 255 && knobVal >= 0){
return WAVEFORM_SINE; 
}
else if (knobVal <= 510 && knobVal > 255){
return WAVEFORM_SQUARE;
}
else if (knobVal <= 765 && knobVal > 510){
return WAVEFORM_TRIANGLE_VARIABLE;
}
else{
return WAVEFORM_PULSE;
}
}

//playKey 
void playKey(){
int x=0; 
x = currWave();
waveformMod1.begin(x);

waveformMod2.begin(x);

waveformMod3.begin(x);

waveformMod4.begin(x);

waveformMod5.begin(x);

waveformMod6.begin(x);

waveformMod7.begin(x);

waveformMod8.begin(x);

waveformMod9.begin(x);

waveformMod10.begin(x);

waveformMod11.begin(x);

waveformMod12.begin(x);

sensorVal12 = analogRead(sensorPin12);
 if (sensorVal12 > 300){
  waveformMod1.amplitude(0.5);
}
else{
  waveformMod1.amplitude(0.0);
}

sensorVal1 = analogRead(sensorPin1);
 if (sensorVal1 > 500){

  waveformMod2.amplitude(0.5);
}
else{

  waveformMod2.amplitude(0.0);
}

sensorVal2 = analogRead(sensorPin2);
 if (sensorVal2 > 500){

  waveformMod3.amplitude(0.5);
}
else{

  waveformMod3.amplitude(0.0);
}

sensorVal3 = analogRead(sensorPin3);
 if (sensorVal3 > 500){
 
  waveformMod4.amplitude(0.5);
}
else{

  waveformMod4.amplitude(0.0);
}

sensorVal4 = analogRead(sensorPin4);
 if (sensorVal4 > 860){

  waveformMod5.amplitude(0.5);
}
else{

  waveformMod5.amplitude(0.0);
}

sensorVal5 = analogRead(sensorPin5);
 if (sensorVal5 > 860){
 
  waveformMod6.amplitude(0.5);
}
else{

  waveformMod6.amplitude(0.0);
}

sensorVal6 = analogRead(sensorPin6);
 if (sensorVal6 > 860){

  waveformMod7.amplitude(0.5);
}
else{

  waveformMod7.amplitude(0.0);
}

sensorVal7 = analogRead(sensorPin7);
 if (sensorVal7 > 860){
 
  waveformMod8.amplitude(0.5);
}
else{
 
  waveformMod8.amplitude(0.0);
}
/*
sensorVal8 = analogRead(sensorPin8);
 if (sensorVal8 > 1000){
  waveformMod9.amplitude(0.5);
}
else{
  waveformMod9.amplitude(0.0);
}

sensorVal9 = analogRead(sensorPin9);
 if (sensorVal9 > 1000){
  waveformMod10.amplitude(0.5);
}
else{
  waveformMod10.amplitude(0.0);
}
*/
sensorVal10 = analogRead(sensorPin10);
 if (sensorVal10 > 860){

  waveformMod11.amplitude(0.5);
}
else{

  waveformMod11.amplitude(0.0);
}

sensorVal11 = analogRead(sensorPin11);
 if (sensorVal11 > 860){

  waveformMod12.amplitude(0.5);
}
else{

  waveformMod12.amplitude(0.0);
}
}
