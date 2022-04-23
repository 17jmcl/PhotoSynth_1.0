#ifndef PlantSynth_bitcrusher_h
#define PlantSynth_bitcrusher_h

#include "Arduino.h" 
#include <Bounce2.h>

class bitCrusher
{
      public:
      void bitCrusherSetup();
      void bitCrusherMix();
      void bitCrusherButton();
      void bitCrusherLed();
      void updatebitcrush();
      void buttonpress();
      float updateknob(float x);
      float updateknob2(float y);
};

#endif
