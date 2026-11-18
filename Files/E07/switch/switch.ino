int myInput;
void setup() {
  Serial.begin(9600);
}

void loop() {
  while(Serial.available()){
    myInput = Serial.read();
    switch(myInput){
    case '0':
      Serial.println("you entered 0");
      break;
    case '1':
      Serial.println("you entered 1");
      break;
    case '2':
      Serial.println("you entered 2");
      break;
    default:
      Serial.println("you entered something else");
      break;
  }
  }
}
