#include "Arduino.h" 
#include "PlantSynth_AstableMultivibrator.h"
#include "PlantSynth_Knob.h"
#include <Bounce2.h>

#define KNOB_PIN A19
#define KNOB_PIN_PLANT2 A20
#define KNOB_PIN_PLANT3 A21
#define BUTTON_PIN 8
#define LED_PIN 24


//setup plant sensor 

void PlantSynthPlant::plantSetup(){
  pinMode(plantPin,INPUT);
}

float scaleKnob(){
scaleNum = smoothKnob(KNOB_PIN,10);
return scaleNum; 
}

float scaleKnob2(){
scaleNum2 = -((((analogRead(A20))) - 1.0) * (1.0 - -1.0) / (1023 - 1) + 0.0)/2;
return scaleNum2; 
}


float scaleKnob3(){
scaleNum3 = ((((analogRead(A21))) - 1.0) * (1.0 - -1.0) / (1023 - 1) + 0.0);
return scaleNum3; 
}


void getFreq(){
  duration1 = pulseIn(plantPin, HIGH);  //Reads a pulse on timer
  duration2 = pulseIn(plantPin, LOW);  //Reads a pulse on timer
  plantdc = float (duration1)/(duration1 + duration2) * 100; 
  plantfreqOrigin = float (1/((0.000001*duration1)+(0.000001*duration2)));
  scaleNum = scaleKnob();
  scaleNum2 = scaleKnob2();
  scaleNum3 = scaleKnob3();
  tremeloplant = (plantdc/80)*.05*scaleNum*10000; 
  plantfreq = plantfreqOrigin * scaleNum; 
  Serial.println(plantfreqOrigin);
  delay(1);
}

void modWave(){
  getFreq();
  waveform1.begin(0.1,tremeloplant,WAVEFORM_SINE);
  
  waveform2.begin(0.1,tremeloplant,WAVEFORM_SINE);
  
  waveform3.begin(0.1,tremeloplant,WAVEFORM_SINE);
  
  waveform4.begin(0.1,tremeloplant,WAVEFORM_SINE);
  
  waveform5.begin(0.1,tremeloplant,WAVEFORM_SINE);
  
  waveform6.begin(0.1,tremeloplant,WAVEFORM_SINE);
  
  waveform7.begin(0.1,tremeloplant,WAVEFORM_SINE);
  
  waveform8.begin(0.1,tremeloplant,WAVEFORM_SINE);
  
  waveform9.begin(0.1,tremeloplant,WAVEFORM_SINE);
  
  waveform10.begin(0.1,tremeloplant,WAVEFORM_SINE);
  
  waveform11.begin(0.1,tremeloplant,WAVEFORM_SINE);
  
  waveform12.begin(0.1,tremeloplant,WAVEFORM_SINE);
  waveform1.offset(scaleNum2);
  waveform2.offset(scaleNum2);
  waveform3.offset(scaleNum2);
  waveform4.offset(scaleNum2);
  waveform5.offset(scaleNum2);
  waveform6.offset(scaleNum2);
  waveform7.offset(scaleNum2);
  waveform8.offset(scaleNum2);
  waveform9.offset(scaleNum2);
  waveform10.offset(scaleNum2);
  waveform11.offset(scaleNum2);
  waveform12.offset(scaleNum2);
}
