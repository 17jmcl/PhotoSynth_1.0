#ifndef PlantSynth_Knob_h
#define PlantSynth_Knob_h

#include "Arduino.h"

class PlantSynthKnob
{
      public:
      void knobSetup(int x);
      float smoothKnob(int y, int z);
};

#endif
