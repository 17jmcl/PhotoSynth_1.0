
#include "Arduino.h"
#include "AudioStream.h"
#include <Bounce2.h>
#include "PlantSynth_bitcrusher.h"
#include "PlantSynth_AstableMultivibrator.h"

#define KNOB_PIN2 A17

void updatebitcrush(){
  float k; 
  float j;
  if (ledState == 1){
    //PRESSED
  k = updateknob2(updatebits);
  bitcrusher1.bits(k); 
  j = updateknob(updatebits);
  bitcrusher1.sampleRate(j); 
  //NEEDS EDIT 
  mixer1.gain(0,0.1);
  mixer3.gain(1,0.2);
  mixer3.gain(0,0.8);
  //TURN ON VERB 
  Serial.println(k); 
  }
  else{
    mixer1.gain(0,0.0);
    mixer3.gain(1,0.0); 
    mixer3.gain(0,1.0); 
}}

void buttonpress(){
  if ( button1.pressed() ) {
    Serial.println("PRESS");
    ledState = !ledState;
    digitalWrite(LED_PIN2,ledState);
}
}

float updateknob2(float y){ 
    float result1; 
    result1 = ((((analogRead(KNOB_PIN2))) - 1.0) * (16 - 1) / (1023 - 1) + 0.0);
    return result1;
    }

float updateknob(float x){ 
    float result1; 
    result1 = plantfreq*10;
    return result1;
    }
