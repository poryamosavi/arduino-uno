String stringKamel = "";
boolean stringAmade = false;


void setup() {
  
}


void loop() {
  serialKhan();
  if(stringAmade){
    Serial.println(stringKamel);
    if(stringKamel == "roshan"){
      digitalWrite(12, HIGH);
      Serial.println("tuye roshan");
    }else if(stringKamel == "khamush"){
      digitalWrite(12, LOW);
      Serial.println("tuye roshan");
    }
    stringKamel = "";
    stringAmade = false;
  }
}


void serialKhan(){
  while (Serial.available()) {
    char vorudi = (char)Serial.read();
    if(vorudi == '\n'){
      stringAmade = true;
    }else{
      stringKamel += vorudi;
    }
  }
}

