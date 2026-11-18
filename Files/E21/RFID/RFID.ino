#include <EEPROM.h>

const int zabooneBarghi = 12;
const int redLED = 11;
const int greenLED = 10;
const int cardButton = 9;
const int maxCardNumber = 3;

char buffer[13];
char validCard[maxCardNumber][13];
byte eepromCardNumber;
int addr = 0;
int isCardOk = 0;

void setup() {
//  for(int i = 0; i < EEPROM.length(); i++){
//    EEPROM.write(i, 0);
//  }
  eepromCardNumber = EEPROM.read(addr);
  if(eepromCardNumber != 0){
    for(int i = 0; i < eepromCardNumber; i++){
      addr = 1 + i*13;
      EEPROM.get(addr, validCard[i]);
    }
  }
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(zabooneBarghi, OUTPUT);
  pinMode(cardButton, INPUT_PULLUP);
  Serial.begin(9600);
  buffer[12] = '\0';
}

void loop() {
  if(eepromCardNumber == 0){
    digitalWrite(redLED, !digitalRead(redLED));
    delay(200);
  }
  while(Serial.available()){
      Serial.readBytes(buffer, 12);
      isCardOk = 0;
      if(eepromCardNumber == 0){
        EEPROM.write(addr, eepromCardNumber);
        addr += sizeof(eepromCardNumber);
        EEPROM.put(addr, buffer);
        digitalWrite(redLED, LOW);
        for(int i = 0; i < 13; i++){
          validCard[eepromCardNumber][i] = buffer[i];
        }
        eepromCardNumber++;
        EEPROM.write(0, eepromCardNumber);
        digitalWrite(greenLED, HIGH);
        digitalWrite(redLED, HIGH);
        delay(1000);
        digitalWrite(greenLED, LOW);
        digitalWrite(redLED, LOW);
      }else{
        if(digitalRead(cardButton) == HIGH){
          for(int i = 0; i < maxCardNumber; i++){
            if(String(buffer) == String(validCard[i])){
              isCardOk = 1;
              digitalWrite(zabooneBarghi, HIGH);
              digitalWrite(greenLED, HIGH);
              digitalWrite(redLED, LOW);
              delay(1000);
              digitalWrite(greenLED, LOW);
              digitalWrite(zabooneBarghi, LOW);
            }
          }
          if(isCardOk != 1){
            digitalWrite(greenLED, LOW);
            digitalWrite(zabooneBarghi, LOW);
            digitalWrite(redLED, HIGH);
            delay(1000);
            digitalWrite(redLED, LOW);
          }
        }else{
          if(eepromCardNumber < maxCardNumber){
            addr = 1 + eepromCardNumber*13;
            EEPROM.put(addr, buffer);
            for(int i = 0; i < 13; i++){
              validCard[eepromCardNumber][i] = buffer[i];
            }
            eepromCardNumber++;
            EEPROM.write(0, eepromCardNumber);
            digitalWrite(greenLED, HIGH);
            digitalWrite(redLED, HIGH);
            delay(1000);
            digitalWrite(greenLED, LOW);
            digitalWrite(redLED, LOW);
          }else{
            digitalWrite(redLED, HIGH);
            delay(1000);
            digitalWrite(redLED, LOW);
            delay(1000);
            digitalWrite(redLED, HIGH);
            delay(1000);
            digitalWrite(redLED, LOW);
            delay(1000);
            digitalWrite(redLED, HIGH);
            delay(1000);
            digitalWrite(redLED, LOW);
            delay(1000);
          }
        }
      }
  }
}
