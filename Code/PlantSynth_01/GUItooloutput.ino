#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <Bounce2.h>

// GUItool: begin automatically generated code
AudioSynthWaveform       waveform12;     //xy=720,847
AudioSynthWaveform       waveform11;     //xy=725,802
AudioSynthWaveform       waveform10;     //xy=731,756
AudioSynthWaveform       waveform1;      //xy=739,414
AudioSynthWaveform       waveform9;      //xy=738,719
AudioSynthWaveform       waveform8;      //xy=739,682
AudioSynthWaveform       waveform3;      //xy=740,496
AudioSynthWaveform       waveform4;      //xy=741,534
AudioSynthWaveform       waveform2;      //xy=742,453
AudioSynthWaveform       waveform6;      //xy=742,604
AudioSynthWaveform       waveform5;      //xy=743,569
AudioSynthWaveform       waveform7;      //xy=747,642
AudioSynthWaveformModulated waveformMod2;   //xy=906,445.5
AudioSynthWaveformModulated waveformMod6;   //xy=906,599.5
AudioSynthWaveformModulated waveformMod1;   //xy=907,407
AudioSynthWaveformModulated waveformMod3;   //xy=908,484.5
AudioSynthWaveformModulated waveformMod4;   //xy=908,524.5
AudioSynthWaveformModulated waveformMod5;   //xy=908,560.5
AudioSynthWaveformModulated waveformMod7;   //xy=908,636.5
AudioSynthWaveformModulated waveformMod9;   //xy=910,708.5
AudioSynthWaveformModulated waveformMod8;   //xy=911,671.5
AudioSynthWaveformModulated waveformMod10;  //xy=912,748.5
AudioSynthWaveformModulated waveformMod11;  //xy=914,789.5
AudioSynthWaveformModulated waveformMod12;  //xy=914,827.5
AudioMixer4              mixer9;         //xy=1102,715.5
AudioMixer4              mixer7;         //xy=1104,562.5
AudioMixer4              mixer8;         //xy=1104,644.5
AudioMixer4              mixer11;        //xy=1270,551.5
AudioMixer4              mixer6;         //xy=1545,967
AudioMixer4              mixer2;         //xy=1547,1058
AudioMixer4              mixer1;         //xy=1548,1138
AudioMixer4              mixer4;         //xy=1551,1223
AudioMixer4              mixer5;         //xy=1551,1299
AudioEffectGranular      granular1;      //xy=1692,961
AudioEffectFlange        flange1;        //xy=1702,1220
AudioEffectReverb        reverb1;        //xy=1705,1056
AudioEffectChorus        chorus1;        //xy=1709,1303
AudioEffectBitcrusher    bitcrusher1;    //xy=1713,1138
AudioMixer4              mixer3;         //xy=1724,504
AudioOutputI2S           is23; //xy=1961,517
AudioConnection          patchCord1(waveform12, 0, waveformMod12, 0);
AudioConnection          patchCord2(waveform12, 0, waveformMod12, 1);
AudioConnection          patchCord3(waveform11, 0, waveformMod11, 0);
AudioConnection          patchCord4(waveform11, 0, waveformMod11, 1);
AudioConnection          patchCord5(waveform10, 0, waveformMod10, 0);
AudioConnection          patchCord6(waveform10, 0, waveformMod10, 1);
AudioConnection          patchCord7(waveform1, 0, waveformMod1, 0);
AudioConnection          patchCord8(waveform1, 0, waveformMod1, 1);
AudioConnection          patchCord9(waveform9, 0, waveformMod9, 0);
AudioConnection          patchCord10(waveform9, 0, waveformMod9, 1);
AudioConnection          patchCord11(waveform8, 0, waveformMod8, 0);
AudioConnection          patchCord12(waveform8, 0, waveformMod8, 1);
AudioConnection          patchCord13(waveform3, 0, waveformMod3, 0);
AudioConnection          patchCord14(waveform3, 0, waveformMod3, 1);
AudioConnection          patchCord15(waveform4, 0, waveformMod4, 0);
AudioConnection          patchCord16(waveform4, 0, waveformMod4, 1);
AudioConnection          patchCord17(waveform2, 0, waveformMod2, 0);
AudioConnection          patchCord18(waveform2, 0, waveformMod2, 1);
AudioConnection          patchCord19(waveform6, 0, waveformMod6, 0);
AudioConnection          patchCord20(waveform6, 0, waveformMod6, 1);
AudioConnection          patchCord21(waveform5, 0, waveformMod5, 0);
AudioConnection          patchCord22(waveform5, 0, waveformMod5, 1);
AudioConnection          patchCord23(waveform7, 0, waveformMod7, 0);
AudioConnection          patchCord24(waveform7, 0, waveformMod7, 1);
AudioConnection          patchCord25(waveformMod2, 0, mixer7, 1);
AudioConnection          patchCord26(waveformMod6, 0, mixer8, 1);
AudioConnection          patchCord27(waveformMod1, 0, mixer7, 0);
AudioConnection          patchCord28(waveformMod3, 0, mixer7, 2);
AudioConnection          patchCord29(waveformMod4, 0, mixer7, 3);
AudioConnection          patchCord30(waveformMod5, 0, mixer8, 0);
AudioConnection          patchCord31(waveformMod7, 0, mixer8, 2);
AudioConnection          patchCord32(waveformMod9, 0, mixer9, 0);
AudioConnection          patchCord33(waveformMod8, 0, mixer8, 3);
AudioConnection          patchCord34(waveformMod10, 0, mixer9, 1);
AudioConnection          patchCord35(waveformMod11, 0, mixer9, 2);
AudioConnection          patchCord36(waveformMod12, 0, mixer9, 3);
AudioConnection          patchCord37(mixer9, 0, mixer11, 2);
AudioConnection          patchCord38(mixer7, 0, mixer11, 0);
AudioConnection          patchCord39(mixer8, 0, mixer11, 1);
AudioConnection          patchCord40(mixer11, 0, mixer3, 0);
AudioConnection          patchCord41(mixer6, granular1);
AudioConnection          patchCord42(mixer2, reverb1);
AudioConnection          patchCord43(mixer1, bitcrusher1);
AudioConnection          patchCord44(mixer4, flange1);
AudioConnection          patchCord45(mixer5, chorus1);
AudioConnection          patchCord46(reverb1, 0, mixer3, 2);
AudioConnection          patchCord47(chorus1, 0, mixer3, 3);
AudioConnection          patchCord48(bitcrusher1, 0, mixer3, 1);
AudioConnection          patchCord49(mixer3, 0, is23, 0);
AudioConnection          patchCord50(mixer3, 0, is23, 1);
AudioControlSGTL5000     sgtl5000_1; //xy=742,296
// GUItool: end automatically generated code

//Global Plant Setup
float plantfreq = 0.0;
float plantfreqOrigin = 0.0;
float plantdc = 0.0; 
unsigned long duration1;  
unsigned long duration2; 
int plantPin = 5;
float scaleNum = 0.0;

//Bitcrusher Global 
float updatebits; 
Button button = Button();
volatile int ledState = LOW;

//Knob class 
int readIndex = 0; 
const int numReadings = 0; 
int knobInputPin = 0; 
int readings[numReadings];


//Global Piano Setup 
  const byte sensorPin1 = A1; 
      int sensorVal1 = 0; 
  
      const byte sensorPin2 = A2; 
      int sensorVal2 = 0; 
      
      const byte sensorPin3 = A3; 
      int sensorVal3 = 0; 
      
      const byte sensorPin4 = A4; 
      int sensorVal4 = 0; 
      
      const byte sensorPin5 = A5; 
      int sensorVal5 = 0; 
      
      const byte sensorPin6 = A6; 
      int sensorVal6 = 0; 
      
      const byte sensorPin7 = A7; 
      int sensorVal7 = 0; 
      
      const byte sensorPin8 = A8; 
      int sensorVal8 = 0; 
      
      const byte sensorPin9 = A9; 
      int sensorVal9 = 0; 
      
      const byte sensorPin10 = A12; 
      int sensorVal10 = 0; 
      
      const byte sensorPin11= A13; 
      int sensorVal11 = 0; 
      
      const byte sensorPin12 = A0; 
      int sensorVal12 = 0; 
