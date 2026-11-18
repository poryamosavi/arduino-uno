const int ledPin = 13;
String stringKamel = "";

unsigned long previousMillis = 0;
const long interval = 20000;

int ledState = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();

  if(currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if(ledState == LOW){
      ledState = HIGH;
    }else{
      ledState = LOW;
    }
    digitalWrite(ledPin, ledState);
  }
  checkSerial();
}

void checkSerial(){
  while (Serial.available()) {
    stringKamel = Serial.readString();
    Serial.println(stringKamel);
  }
}

