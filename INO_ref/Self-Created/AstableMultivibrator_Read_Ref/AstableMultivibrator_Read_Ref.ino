/*
int ledPin = 13;  // LED connected to digital pin 13
float inPin = 3.0;  // pushbutton connected to digital pin 7
int val = 0;      // variable to store the read value

void setup()
{
  pinMode(inPin,INPUT);
  Serial.begin(57600);
  while (!Serial);
}

void loop()
{
  Serial.println(digitalRead(inPin));
  delay(10);
}

-------
*/
int inPin = 3;  //attach to the third pin of NE555

unsigned long
duration1;  //the variable to store the
//HIGH length

unsigned long
duration2;  //the variable to store the
//LOW length

float dc = 0.0;  //the variable to store the duty cycle
float freq = 0.0;
void setup()

{

  pinMode(inPin, INPUT);  //set the ne555 as an input

  Serial.begin(57600);
  while (!Serial);

}

void loop()

{

  duration1 = pulseIn(inPin, HIGH);  //Reads a pulse on ne555
  duration2 = pulseIn(inPin, LOW);  //Reads a pulse on ne555
  dc = float (duration1)/(duration1 + duration2) * 100;
  freq = float (1/((0.000001*duration1)+(0.000001*duration2)));

  Serial.print("Duty cycle: ");

  Serial.println(dc);  //print the length of the pulse on the serial
  
  Serial.print("D1: ");

  Serial.println(duration1);  //print the length of the pulse on the serial

  Serial.print("D2: ");

  Serial.println(duration2);  //print the length of the pulse on the serial

  Serial.print("Frequency: ");

  Serial.println(freq);  //print the length of the pulse on the serial


  Serial.println();  //print an blank on serial monitor

  delay(500); 
//wait for 500 microseconds

}
