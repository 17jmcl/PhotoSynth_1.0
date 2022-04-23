#include "Arduino.h" 
#include "PlantSynth_AstableMultivibrator.h"
#include "Knobclass.h"
#include <Bounce2.h>

#define KNOB_PIN A19
#define BUTTON_PIN 8
#define LED_PIN 24


//setup plant sensor 

void PlantSynthPlant::plantSetup(){
  pinMode(plantPin,INPUT);
}

void scaleKnob(){
scaleNum = (((analogRead(KNOB_PIN)) - 1.0 ) * ( 1000 - 0.0 ) / (1023 - 1) + 0.0);
}

void getFreq(){
  duration1 = pulseIn(plantPin, HIGH);  //Reads a pulse on timer
  duration2 = pulseIn(plantPin, LOW);  //Reads a pulse on timer
  plantdc = float (duration1)/(duration1 + duration2) * 100; 
  plantfreqOrigin = float (1/((0.000001*duration1)+(0.000001*duration2)));
  plantfreq = plantfreqOrigin * scaleNum; 
  delay(1);
}

void modWave(){
  scaleKnob();
  getFreq();
  waveform1.begin(0.1,plantfreq,WAVEFORM_SINE);
  
  waveform2.begin(0.1,plantfreq,WAVEFORM_SINE);
  
  waveform3.begin(0.1,plantfreq,WAVEFORM_SINE);
  
  waveform4.begin(0.1,plantfreq,WAVEFORM_SINE);
  
  waveform5.begin(0.1,plantfreq,WAVEFORM_SINE);
  
  waveform6.begin(0.1,plantfreq,WAVEFORM_SINE);
  
  waveform7.begin(0.1,plantfreq,WAVEFORM_SINE);
  
  waveform8.begin(0.1,plantfreq,WAVEFORM_SINE);
  
  waveform9.begin(0.1,plantfreq,WAVEFORM_SINE);
  
  waveform10.begin(0.1,plantfreq,WAVEFORM_SINE);
  
  waveform11.begin(0.1,plantfreq,WAVEFORM_SINE);
  
  waveform12.begin(0.1,plantfreq,WAVEFORM_SINE);
}
