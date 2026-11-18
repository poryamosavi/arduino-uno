#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 namatekRadio(7, 8); //CE, CSN
const byte address[6] = "00001";
const int relayPin = 9;

void setup() {
  pinMode(relayPin, OUTPUT);
  namatekRadio.begin();
  namatekRadio.openReadingPipe(0, address);
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
}
