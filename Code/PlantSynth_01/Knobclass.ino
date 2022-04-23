#include "Arduino.h" 
#include "Knobclass.h"
#include <Bounce2.h>

int total = 0; 
int average = 0; 
      
void setupKnob(int x){
 for (int thisReading = 0; thisReading < x; thisReading++) {
    readings[thisReading] = 0;
  }
}
