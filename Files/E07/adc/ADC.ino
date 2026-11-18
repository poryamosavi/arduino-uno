void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(12, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int x = analogRead(A0);
  float realVoltage = (x * 4.61) / 1023.0;
  float miliVolts = realVoltage * 1000.0;
  float temp = miliVolts / 10.0;
  Serial.print(temp);
  Serial.println(" Deg");
  if(temp > 32.5){
    digitalWrite(12, HIGH);
  }else if(temp < 31.5){
    digitalWrite(12, LOW);
  }
  delay(100);
}
