int button = 12;
int led = 13;
void setup() {
  // put your setup code here, to run once:
  //set pin 13 as output
  pinMode(led, OUTPUT);
  //set pin 12 as input
  pinMode(button, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //turn led on if button pressed
  if(digitalRead(button) == HIGH){
    digitalWrite(led, HIGH);
    delay(200);
    digitalWrite(led, LOW);
    delay(200);
      digitalWrite(led, HIGH);
    delay(200);
    digitalWrite(led, LOW);
    delay(200);
      digitalWrite(led, HIGH);
    delay(200);
    digitalWrite(led, LOW);
    delay(200);
      digitalWrite(led, HIGH);
    delay(200);
    digitalWrite(led, LOW);
    delay(200);
      digitalWrite(led, HIGH);
    delay(200);
    digitalWrite(led, LOW);
    delay(200);
  }else{
    digitalWrite(led, LOW);
  }
}
