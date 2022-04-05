# PhotoSynth
 PhotoSynth: A synth using electromagnetic data to modulate effects. Currently in development.
 
Date Updated Last: 04/04/2022

Julie McLaughlin 
Thesis Project for Temple University 
Advisor: Dr. Adam Vidiksis 

Description (What it does, technology used, challenges and future features)
A monophonic synth with a 12 note keyboard using electromagnetic data to modulate effects. 
It uses Teensy 3.5, a custom PCB board made with Fusion 360 Autodesk, and Teensyduino IDE. Currently the PCB is being completed for manufacturing and the code is written to input all sensor data. Next steps are to complete the PCB, design a 3D casing, write code to analyze the input signals, and write functions for various effects and sounds. Future features will be updated here shortly. 

Table of Contents
- Project Information
- Description
- How to use the project
- Dependencies 
- BOM
- Credits
- Future developments for READme and Github documentation 
    -License
    -How to Contribute
    -Test code
    -Additional Links and Resources
    -Github badges 
- Notes

How to use the project:
Download SCH,PCB,Gerber, and BOM and open with your preferred developement software (example: Autodesk Fusion 360). Open ino files with Teensyduino or Arduino IDE, adjust your settings, and compile/run the code. 

-------------------------------------------------------------------------------

Dependencies: 
TeensyDuino: PJRC derivative of Arduino 
PJRC Audio Tool: Audio Library (PJRC)
PJRC EEPROMex: Non-Volatile data storage (PJRC) 
Bounce2: Debouncing library for Arduino 

Bill of Materials: (Insert link when edited)

Credits:

Circuit for the reading of Snapelectrodes based on BiodataSonificationBreadboardKit from Sam Cusumano electricityforprogress 

-------------------------------------------------------------------------------

Sections to add later to README: 
License (Potential future section)

How to Contribute (Potential future section)

Test (Potential future section)

Additional Links and Resources (Potential future section)

(Add badges to quick update and link from github)

-------------------------------------------------------------------------------

Github Notes: 
Add gitignore for dependencies and such 
Add Branches and figure out how to merge to main 







