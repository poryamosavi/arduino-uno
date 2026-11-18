#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int backLightPin = 9;
const int brightnessPin = 10;
const int brightnessThreshold = 30;
const int loadingIntervalDelay = 1;
const int showTextAnimateDelay = 1;
const int LcdColsCount = 16;
const int joyStickBtnPin = 6;
const int joyStickXPin = A1;
const int joyStickYPin = A0;
const int debounceDelay = 200;

int loadingFinished = 0;
int joyStickBtn = 1;
int countDownDone = 0;
int joyStickX;
int joyStickY;
char screenArray[] = {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'B', 'A', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'};
int adamakOldScreenIndex = 16;
int adamakNewScreenIndex = 16;
int brickScreenIndex = 15;
unsigned long lastDebounceTime1 = 0;
unsigned long lastDebounceTime2 = 0;
unsigned long lastDebounceTime3 = 0;
unsigned long lastDebounceTime4 = 0;
int lastDebounceTime1Lock = 0;
int lastDebounceTime2Lock = 0;
int lastDebounceTime3Lock = 0;
int lastDebounceTime4Lock = 0;
int gameScore = 0;

byte brick[8] = {
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};

byte armsDown[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
};

void loadGame(){
  setLcdBrightness(255);
  turnLcdOn();
  showTextAnimate("NAMATEK", strlen("NAMATEK"));
  showTextAnimate("BEE", strlen("BEE"));
  showTextAnimate("PRESENTS", strlen("PRESENTS"));
  showTextAnimate("READY?", strlen("Ready?"));
  lcd.setCursor(1, 1);
  lcd.print("Press Start Btn");
  loadingFinished = 1;
}
void setBacklightBrightness(int brightness){
  analogWrite(backLightPin, brightness);
}
void setLcdBrightness(int brightness){
  analogWrite(brightnessPin, brightness);
}
void turnLcdOn(){
  for(int i = 0; i < 256; i++){
    setBacklightBrightness(i);
    delay(loadingIntervalDelay);
  }
}
void turnLcdOff(){
  for(int i = 255; i > 0; i--){
    setBacklightBrightness(i);
    delay(loadingIntervalDelay);
  }
}
void showCharacters(){
  for(int i = 255; i > brightnessThreshold; i--){
    setLcdBrightness(i);
    delay(loadingIntervalDelay);
  }
}
void hideCharacters(){
  for(int i = brightnessThreshold; i < 256; i++){
    setLcdBrightness(i);
    delay(loadingIntervalDelay);
  }
}
void showTextAnimate(const char *text, int len){
  hideCharacters();
  lcd.clear();
  lcd.setCursor((LcdColsCount - len)/2, 0);
  lcd.print(text);
  showCharacters();
  delay(showTextAnimateDelay);
}
void renderScreen(){
  for(int i = 0; i < 32; i++){
    lcd.setCursor(i%16, i/16);
    if(screenArray[i] == 'A'){
      lcd.write((byte)0);
    }else if(screenArray[i] == 'B'){
      lcd.write((byte)1);
    }else{
      lcd.print(" ");
    }
  }
}
void calculateAdamakPosition(){
  screenArray[adamakOldScreenIndex] = '0';
  if(screenArray[adamakNewScreenIndex] != 'B'){
    screenArray[adamakNewScreenIndex] = 'A';
  }else{
    gameOver();
  }
  adamakOldScreenIndex = adamakNewScreenIndex;
}

void calculateBrickPosition(){
  static int frameCounter = 0;
  long randomNumber = random(0,2);
  frameCounter++;
  if(frameCounter >= 1){
    if(brickScreenIndex != 0 && brickScreenIndex != 16){
      screenArray[brickScreenIndex] = '0';
      brickScreenIndex--;
      if(screenArray[brickScreenIndex] != 'A'){
        screenArray[brickScreenIndex] = 'B';
      }else{
        gameOver();
      }
    }else{
      gameScore++;
      Serial.print("Your score is : ");
      Serial.println(gameScore);
      screenArray[brickScreenIndex] = '0';
      if(randomNumber == 0){
        if(screenArray[15] != 'A'){
          screenArray[15] = 'B';
          brickScreenIndex = 15;
        }else{
          gameOver();
        }
      }else{
        if(screenArray[31] != 'A'){
          screenArray[31] = 'B';
          brickScreenIndex = 31;
        }else{
          gameOver();
        }
      }
    }
    frameCounter = 0;
  }
}
void gameOver(){
  int i = 0;
  loadingFinished = 0;
  turnLcdOff();
  turnLcdOn();
  lcd.clear();
  showTextAnimate("Game Over", strlen("Game Over"));
  lcd.setCursor(1, 1);
  lcd.print("Press Start Btn");
  loadingFinished = 1;
  countDownDone = 0;
  joyStickBtn = HIGH;
  adamakOldScreenIndex = 16;
  adamakNewScreenIndex = 16;
  brickScreenIndex = 15;
  for(int i = 0; i < 32; i++){
    screenArray[i] = '0';
  }
  screenArray[16] = 'A';
  screenArray[15] = 'B';
  gameScore = 0;
}

void setup() {
  pinMode(backLightPin, OUTPUT);
  pinMode(brightnessPin, OUTPUT);
  pinMode(joyStickBtnPin, INPUT_PULLUP);
  pinMode(joyStickXPin, INPUT);
  pinMode(joyStickYPin, INPUT);

  lcd.begin(16, 2);
  lcd.createChar(0, armsDown);
  lcd.createChar(1, brick);
  loadGame();

  Serial.begin(9600);
}

void loop() {
  while(!loadingFinished);
  while(joyStickBtn){
    joyStickBtn = digitalRead(joyStickBtnPin);
  }
  if(!countDownDone){
    lcd.clear();
    lcd.home();
    showTextAnimate("3", strlen("3"));
    showTextAnimate("2", strlen("2"));
    showTextAnimate("1", strlen("1"));
    hideCharacters();
    lcd.clear();
    showCharacters();
    countDownDone = 1;
  }
  renderScreen();
  joyStickX = analogRead(joyStickXPin);
  joyStickY = analogRead(joyStickYPin);

  //Right
  if(joyStickX < 300){
    if(!lastDebounceTime1Lock){
      lastDebounceTime1 = millis();
      lastDebounceTime1Lock = 1;
    }
    if((millis() - lastDebounceTime1) > debounceDelay){
      if(adamakNewScreenIndex != 15 && adamakNewScreenIndex != 31){
        adamakNewScreenIndex++;
      }
      lastDebounceTime1Lock = 0;
    }
  }

  //Left
  if(joyStickX > 700){
    if(!lastDebounceTime2Lock){
      lastDebounceTime2 = millis();
      lastDebounceTime2Lock = 1;
    }
    if((millis() - lastDebounceTime2) > debounceDelay){
      if(adamakNewScreenIndex != 0 && adamakNewScreenIndex != 16){
        adamakNewScreenIndex--;
      }
      lastDebounceTime2Lock = 0;
    }
  }

  //Up
  if(joyStickY < 300){
    if(!lastDebounceTime3Lock){
      lastDebounceTime3 = millis();
      lastDebounceTime3Lock = 1;
    }
    if((millis() - lastDebounceTime3) > debounceDelay){
      if(adamakNewScreenIndex > 15){
        adamakNewScreenIndex -= 16;
      }
      lastDebounceTime3Lock = 0;
    }
  }

  //Down
  if(joyStickY > 700){
    if(!lastDebounceTime4Lock){
      lastDebounceTime4 = millis();
      lastDebounceTime4Lock = 1;
    }
    if((millis() - lastDebounceTime4) > debounceDelay){
      if(adamakNewScreenIndex < 16){
        adamakNewScreenIndex += 16;
      }
      lastDebounceTime4Lock = 0;
    }
  }
  calculateAdamakPosition();
  calculateBrickPosition();
  delay(10);
}
