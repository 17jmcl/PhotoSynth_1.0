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
      float scaleKnob();
      float scaleKnob2();
      float scaleKnob3();
      void knobSetup();
      void smoothKnob();
};

#endif
