#include "Arduino.h" 
#include "PlantSynth_Knob.h"

void PlantSynthKnob::knobSetup(int x){
  for (int y = 0; y < x; y++) {
    readings[y] = 0;
  }
}

float smoothKnob( int y, float z){
for (int x=0; x<z; x++){
  total = total - readings[x]; // subtract last old data 
  readings[x] = analogRead(A19); // read new input at x indx 
  total = total + readings[x]; //add one new data 
  if (x >= z){
    readIndex = 0;
  }

  average = total/z;
  return average;
  delay(1);
}}
