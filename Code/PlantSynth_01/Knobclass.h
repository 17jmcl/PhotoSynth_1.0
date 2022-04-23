#ifndef Knobclass_h
#define Knobclass_h

#include "Arduino.h"
#include "AudioStream.h"

class Knobclass
{
      public:
      int total;
      int average; 
      void setupKnob(int x);
      void smoothKnob();
};

#endif
