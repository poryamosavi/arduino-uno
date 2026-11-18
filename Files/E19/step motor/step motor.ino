const int coila1 = 12;
const int coila2 = 11;
const int coilb1 = 10;
const int coilb2 = 9;
const int stepDelay = 2;

void excitePin(int pin){
  digitalWrite(pin, HIGH);
}
void deExcitePin(int pin){
  digitalWrite(pin, LOW);
}
void startMotorCCW(int loopCount){
  for(int i = 0; i < loopCount; i++){
    excitePin(coila1);
    deExcitePin(coila2);
    deExcitePin(coilb1);
    deExcitePin(coilb2);
    delay(stepDelay);
    
    deExcitePin(coila1);
    deExcitePin(coila2);
    deExcitePin(coilb1);
    excitePin(coilb2);
    delay(stepDelay);
    
    deExcitePin(coila1);
    excitePin(coila2);
    deExcitePin(coilb1);
    deExcitePin(coilb2);
    delay(stepDelay);
    
    deExcitePin(coila1);
    deExcitePin(coila2);
    excitePin(coilb1);
    deExcitePin(coilb2);
    delay(stepDelay);
  }
}
void startMotorCW(int loopCount){
  for(int i = 0; i < loopCount; i++){
    excitePin(coila1);
    deExcitePin(coila2);
    deExcitePin(coilb1);
    deExcitePin(coilb2);
    delay(stepDelay);

    deExcitePin(coila1);
    deExcitePin(coila2);
    excitePin(coilb1);
    deExcitePin(coilb2);
    delay(stepDelay);
    
    deExcitePin(coila1);
    excitePin(coila2);
    deExcitePin(coilb1);
    deExcitePin(coilb2);
    delay(stepDelay);

    deExcitePin(coila1);
    deExcitePin(coila2);
    deExcitePin(coilb1);
    excitePin(coilb2);
    delay(stepDelay);
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(coila1, OUTPUT);
  pinMode(coila2, OUTPUT);
  pinMode(coilb1, OUTPUT);
  pinMode(coilb2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  startMotorCW(128);
  delay(100);
  startMotorCCW(128);
  delay(100);
}
