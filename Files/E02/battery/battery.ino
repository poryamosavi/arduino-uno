/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(14, HIGH);
  delay(100);
  digitalWrite(15, HIGH);
  delay(100);
  digitalWrite(16, HIGH);
  delay(100);
  digitalWrite(17, HIGH);
  delay(100);
  digitalWrite(18, HIGH);
  delay(100);
  digitalWrite(19, HIGH);
  delay(100);
  digitalWrite(3, HIGH);
  delay(100);
  digitalWrite(4, HIGH);
  delay(100);
  digitalWrite(5, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(100);
  digitalWrite(14, LOW);
  delay(100);
  digitalWrite(15, LOW);
  delay(100);
  digitalWrite(16, LOW);
  delay(100);
  digitalWrite(17, LOW);
  delay(100);
  digitalWrite(18, LOW);
  delay(100);
  digitalWrite(19, LOW);
  delay(100);
  digitalWrite(3, LOW);
  delay(100);
  digitalWrite(4, LOW);
  delay(100);
  digitalWrite(5, LOW);
  delay(100);
}
