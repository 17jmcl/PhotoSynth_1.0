
#include "Arduino.h"
#include "AudioStream.h"
#include <Bounce2.h>
#include "PlantSynth_bitcrusher.h"

#define BUTTON_PIN2 10 
#define LED_PIN2 28
#define KNOB_PIN2 A17

void bitCrusherSetup(){
  bitCrusherMix();
  bitCrusherButton();
  bitCrusherLed();
}

void bitCrusherMix(){
  
}

void bitCrusherButton(){
  button.attach( BUTTON_PIN2, INPUT );
  button.interval(5); 
  button.setPressedState(LOW); 
  attachInterrupt((digitalPinToInterrupt(BUTTON_PIN2)), buttonpress, CHANGE);
  
}

void bitCrusherLed(){
  pinMode(LED_PIN2,OUTPUT);
  digitalWrite(LED_PIN2,ledState);
}

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
  mixer1.gain(0,0.3);
  mixer3.gain(1,0.6);
  mixer3.gain(0,0.4);
  //TURN ON VERB 
  Serial.println(k); 
  }
  else{
    mixer1.gain(0,0.0);
    mixer3.gain(1,0.0); 
    mixer3.gain(0,1.0); 
}}

void buttonpress(){
  if ( button.pressed() ) {
    ledState = !ledState;
    digitalWrite(LED_PIN,ledState);
}
}

float updateknob2(float y){ 
    float result1; 
    result1 = ((analogRead(KNOB_PIN) - 1.0) * (16 - 1) / (1023 - 1) + 0.0);
    return result1;
    }

float updateknob(float x){ 
    float result1; 
    result1 = ((analogRead(KNOB_PIN) - 1.0) * (44100 - 200) / (1023 - 1) + 0.0);
    return result1;
    }
