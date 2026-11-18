int button = 12;
int led = 13;
int counter = 0;
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
    if(counter % 3 == 0){
      digitalWrite(led, HIGH);
      delay(200);
      digitalWrite(led, LOW);
      delay(500);
      counter++;
    }else if(counter % 3 == 1){
      digitalWrite(led, HIGH);
      delay(200);
      digitalWrite(led, LOW);
      delay(200);
      digitalWrite(led, HIGH);
      delay(200);
      digitalWrite(led, LOW);
      delay(500);
      counter++;
    }else if(counter % 3 == 2){
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
      counter = 0;
      delay(500);
    }
  }
}
