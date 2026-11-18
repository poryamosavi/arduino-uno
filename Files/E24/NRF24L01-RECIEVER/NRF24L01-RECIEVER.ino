#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 namatekRadio(7, 8); //CE, CSN
const byte address[6] = "00001";
const int relayPin = 9;
const int lm35Pin = A0;

unsigned long currentMillis = 0;
unsigned long prevMillis = 0;
int interval = 1000;
byte temp = 0;

void setup() {
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
  pinMode(lm35Pin, INPUT);
  namatekRadio.begin();
  namatekRadio.openReadingPipe(1, address);
  namatekRadio.setPALevel(RF24_PA_MIN);
  namatekRadio.startListening();
}

void loop() {
  if(namatekRadio.available()){
    char command;
    namatekRadio.read(&command, sizeof(command));
    if(command == 1){
      digitalWrite(relayPin, HIGH);
    }else if(command == 2){
      digitalWrite(relayPin, LOW);
    }
  }
  currentMillis = millis();
  if(currentMillis - prevMillis > interval){
    temp = map(analogRead(lm35Pin), 0, 1023, 0, 500);
    namatekRadio.stopListening();
    namatekRadio.openWritingPipe(address);
    namatekRadio.write(&temp, sizeof(temp));
    namatekRadio.startListening();
    prevMillis = currentMillis;
  }
}
