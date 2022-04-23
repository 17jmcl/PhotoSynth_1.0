#include "Arduino.h"
#include "PlantSynth_Piano.h"
#include "PlantSynth_AstableMultivibrator.h"
#include "PlantSynth_bitcrusher.h"

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
AudioMemory(20);
while (!Serial); 

//setup sgtl5000_1
sgtl5000_1.enable();
sgtl5000_1.volume(0.5);

//setup main mixers 
mixer3.gain(0,0.9);

//setup Piano
PlantSynthPiano newpiano;
newpiano.pianoSetup();

PlantSynthPlant newplant; 
newplant.plantSetup();


}

void loop() {
  // put your main code here, to run repeatedly:
playKey();
modWave();
}
