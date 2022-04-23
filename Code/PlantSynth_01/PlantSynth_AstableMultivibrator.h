#ifndef PlantSynth_AstableMultivibrator_h
#define PlantSynth_AstableMultivibrator_h

#include "Arduino.h"
#include "AudioStream.h"

class PlantSynthPlant
{
      public:
      void plantSetup();
      void getFreq();
      void modWave();
      void modFX1();
      void modFX2();
      void scaleKnob();
};

#endif
