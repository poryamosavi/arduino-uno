#include <Keypad.h>

#define maxBufferSize 5

const byte ROWS = 4;
const byte COLS = 3;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

String correctPassword = "1245";

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3};

char keyBuffer[maxBufferSize + 1];
char keyBufferIndex = 0;

Keypad mehradKeypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  mehradKeypad.addEventListener(mehradKeypadEvent);
  keyBuffer[maxBufferSize] = '\0';
}

void loop() {
  char mehardClick = mehradKeypad.getKey();
}

void mehradKeypadEvent(KeypadEvent key){
  switch(mehradKeypad.getState()){
    case PRESSED:
      break;
    case RELEASED:
      if(key != '*'){
        keyBuffer[keyBufferIndex] = key;
        keyBufferIndex++;
        if(keyBufferIndex > maxBufferSize){
          resetBuffer();
          digitalWrite(12, HIGH);
          delay(500);
          digitalWrite(12, LOW);
        }
      }else{
        if((String)keyBuffer == correctPassword){
          digitalWrite(11 , HIGH);
          delay(500);
          digitalWrite(11, LOW);
        }else{
          digitalWrite(12, HIGH);
          delay(500);
          digitalWrite(12, LOW);
        }
        Serial.println(keyBuffer);
        resetBuffer();
      }
      break;
    case HOLD:
      break;
  }
}

void resetBuffer(){
  keyBufferIndex = 0;
  for(int i = 0; i < maxBufferSize; i++){
    keyBuffer[i] = '\0';
  }
}
