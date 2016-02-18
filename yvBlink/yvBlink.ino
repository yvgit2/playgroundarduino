/*
  yvBlink
  Turns on an LED on for x second, then off for y second, repeatedly.
  Serial.println
 
  This example code is in the public domain.
 */

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
// Global mutable delay wait time
int delayH = 100;
int delayL = 1000;

// the setup routine runs once when you press reset:
void setup() {      
  Serial.begin(9600);          //  setup serial  sinon pas de serial println
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);  
  Serial.println("Setup");  
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH); // turn the LED on (HIGH is the voltage level)
 
  Serial.println("HIGH");  // Print a la console
  Serial.print("delay high: ");
  Serial.print(delayH);
  Serial.println("");
  
  delay(delayH); // wait time for a delay
   
  digitalWrite(led, LOW); // turn the LED off by making the voltage LOW
  
  Serial.println("LOW");  // Print a la console
  Serial.print("delay low: ");
  Serial.print(delayL);
  Serial.println("");
  
  delay(delayL);               // wait time delayL 
}
