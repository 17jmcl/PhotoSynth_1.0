#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <Bounce2.h>
#include "Arduino.h"
#include "PlantSynth_Piano.h"
#include "PlantSynth_AstableMultivibrator.h"
#include "PlantSynth_bitcrusher.h"
#include "PlantSynth_Knob.h"

//bitcrush
#define BUTTON_PIN2 10 
#define LED_PIN2 28

// GUItool: begin automatically generated code
AudioSynthWaveform       waveform1;      //xy=1104.500015258789,2270.0000343322754
AudioSynthWaveform       waveform11;     //xy=1105.000015258789,2163.750033378601
AudioSynthWaveform       waveform12;     //xy=1106.250015258789,2223.7500343322754
AudioSynthWaveform       waveform5;      //xy=1109.500015258789,1946.0000267028809
AudioSynthWaveform       waveform3;      //xy=1110.000015258789,1824.0000267028809
AudioSynthWaveform       waveform9;      //xy=1109.250015258789,2124.500030517578
AudioSynthWaveform       waveform7;      //xy=1111.750015258789,1979.5000295639038
AudioSynthWaveform       waveform6;      //xy=1112.000015258789,2019.5000305175781
AudioSynthWaveform       waveform10;     //xy=1112.250015258789,2087.7500324249268
AudioSynthWaveform       waveform8;      //xy=1114.000015258789,2052.5000314712524
AudioSynthWaveform       waveform4;      //xy=1114.750015258789,1902.0000286102295
AudioSynthWaveform       waveform2;      //xy=1115.250015258789,1860.7500286102295
AudioSynthWaveformModulated waveformMod6;   //xy=1273.5000178813934,2015.7500305175781
AudioSynthWaveformModulated waveformMod2;   //xy=1276,1863
AudioSynthWaveformModulated waveformMod3;   //xy=1277,1825
AudioSynthWaveformModulated waveformMod4;   //xy=1278,1902
AudioSynthWaveformModulated waveformMod5;   //xy=1278,1942
AudioSynthWaveformModulated waveformMod7;   //xy=1278,1978
AudioSynthWaveformModulated waveformMod8;   //xy=1278,2054
AudioSynthWaveformModulated waveformMod9;   //xy=1280,2126
AudioSynthWaveformModulated waveformMod10;  //xy=1281,2089
AudioSynthWaveformModulated waveformMod11;  //xy=1282,2166
AudioSynthWaveformModulated waveformMod1;   //xy=1284.0000228881836,2278.7500343322754
AudioSynthWaveformModulated waveformMod12;  //xy=1289.0000228881836,2220.7500324249268
AudioMixer4              mixer8;         //xy=1474,1980
AudioMixer4              mixer10;        //xy=1479.0000228881836,2098.250030517578
AudioMixer4              mixer9;         //xy=1494.5000228881836,2199.250030517578
AudioMixer4              mixer1;         //xy=1503.0000228881836,2499.7500381469727
AudioEffectBitcrusher    bitcrusher1;    //xy=1671.7500305175781,2456.0000381469727
AudioMixer4              mixer11;        //xy=1676.0000228881836,1975.5000305175781
AudioMixer4              mixer3;         //xy=1864.7500267028809,1985.5000305175781
AudioEffectDelay         delay1;         //xy=1887.5000305175781,2150.000030517578
AudioMixer4              mixer6;         //xy=1915,2385
AudioMixer4              mixer2;         //xy=1917,2476
AudioMixer4              mixer4;         //xy=1921,2641
AudioOutputI2S           i2s1;           //xy=2056.000030517578,2052.2500324249268
AudioEffectGranular      granular1;      //xy=2062,2379
AudioEffectFlange        flange1;        //xy=2072,2638
AudioEffectReverb        reverb1;        //xy=2075,2474
AudioConnection          patchCord1(waveform1, 0, waveformMod1, 1);
AudioConnection          patchCord2(waveform1, 0, waveformMod1, 0);
AudioConnection          patchCord3(waveform11, 0, waveformMod11, 1);
AudioConnection          patchCord4(waveform11, 0, waveformMod11, 0);
AudioConnection          patchCord5(waveform12, 0, waveformMod12, 1);
AudioConnection          patchCord6(waveform12, 0, waveformMod12, 0);
AudioConnection          patchCord7(waveform5, 0, waveformMod5, 1);
AudioConnection          patchCord8(waveform5, 0, waveformMod5, 0);
AudioConnection          patchCord9(waveform3, 0, waveformMod3, 1);
AudioConnection          patchCord10(waveform3, 0, waveformMod3, 0);
AudioConnection          patchCord11(waveform9, 0, waveformMod9, 1);
AudioConnection          patchCord12(waveform9, 0, waveformMod9, 0);
AudioConnection          patchCord13(waveform7, 0, waveformMod7, 1);
AudioConnection          patchCord14(waveform7, 0, waveformMod7, 0);
AudioConnection          patchCord15(waveform6, 0, waveformMod6, 1);
AudioConnection          patchCord16(waveform6, 0, waveformMod6, 0);
AudioConnection          patchCord17(waveform10, 0, waveformMod10, 1);
AudioConnection          patchCord18(waveform10, 0, waveformMod10, 0);
AudioConnection          patchCord19(waveform8, 0, waveformMod8, 1);
AudioConnection          patchCord20(waveform8, 0, waveformMod8, 0);
AudioConnection          patchCord21(waveform4, 0, waveformMod4, 1);
AudioConnection          patchCord22(waveform4, 0, waveformMod4, 0);
AudioConnection          patchCord23(waveform2, 0, waveformMod2, 1);
AudioConnection          patchCord24(waveform2, 0, waveformMod2, 0);
AudioConnection          patchCord25(waveformMod6, 0, mixer10, 1);
AudioConnection          patchCord26(waveformMod2, 0, mixer8, 1);
AudioConnection          patchCord27(waveformMod3, 0, mixer8, 0);
AudioConnection          patchCord28(waveformMod4, 0, mixer8, 2);
AudioConnection          patchCord29(waveformMod5, 0, mixer8, 3);
AudioConnection          patchCord30(waveformMod7, 0, mixer10, 0);
AudioConnection          patchCord31(waveformMod8, 0, mixer10, 2);
AudioConnection          patchCord32(waveformMod9, 0, mixer9, 0);
AudioConnection          patchCord33(waveformMod10, 0, mixer10, 3);
AudioConnection          patchCord34(waveformMod11, 0, mixer9, 1);
AudioConnection          patchCord35(waveformMod1, 0, mixer9, 3);
AudioConnection          patchCord36(waveformMod12, 0, mixer9, 2);
AudioConnection          patchCord37(mixer8, 0, mixer11, 0);
AudioConnection          patchCord38(mixer10, 0, mixer11, 1);
AudioConnection          patchCord39(mixer9, 0, mixer11, 2);
AudioConnection          patchCord40(mixer1, bitcrusher1);
AudioConnection          patchCord41(mixer1, delay1);
AudioConnection          patchCord42(bitcrusher1, 0, mixer3, 1);
AudioConnection          patchCord43(mixer11, 0, mixer3, 0);
AudioConnection          patchCord44(mixer11, 0, mixer1, 0);
AudioConnection          patchCord45(mixer3, 0, i2s1, 0);
AudioConnection          patchCord46(mixer3, 0, i2s1, 1);
AudioConnection          patchCord47(delay1, 1, mixer3, 2);
AudioConnection          patchCord48(mixer6, granular1);
AudioConnection          patchCord49(mixer2, reverb1);
AudioConnection          patchCord50(mixer4, flange1);
AudioControlSGTL5000     sgtl5000_1;     //xy=903.2500152587891,1751.5000257492065
// GUItool: end automatically generated code




//Global Plant Setup
float plantfreq = 0.0;
float plantfreqOrigin = 0.0;
float plantdc = 0.0; 
unsigned long duration1;  
unsigned long duration2; 
int plantPin = 5;
float scaleNum = 0.0;
float scaleNum2 = 0.0;
float scaleNum3 = 0.0;
float tremeloplant=  0.0;

//Bitcrusher Global 
float updatebits; 
Button button1 = Button();
volatile int ledState = LOW;

//Knob class 
int readIndex = 0; 
const int numReadings = 0; 
int knobInputPin = 0; 
int readings[numReadings];
float total=0.0;
float average=0.0; 


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
