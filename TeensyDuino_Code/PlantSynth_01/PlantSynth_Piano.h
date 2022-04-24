#ifndef PlantSynth_Piano_h
#define PlantSynth_Piano_h

#include "Arduino.h"
#include "AudioStream.h"

class PlantSynthPiano
{
      public:
      void pianoSetup();
      void mixGainSetup();
      void setPianoHz();
      void setWaveForm();
      void playKey();
};

#endif
