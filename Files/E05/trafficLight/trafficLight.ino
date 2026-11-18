#define top 11
#define topRight 10
#define topLeft 12
#define bottom 8
#define bottomRight 7
#define bottomLeft 9
#define middle 6
#define green 3
#define yellow 4
#define red 5


int mode = 1;
String stringKamel = "";
boolean stringAmade = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(top, OUTPUT);
  pinMode(topRight, OUTPUT);
  pinMode(topLeft, OUTPUT);
  pinMode(bottom, OUTPUT);
  pinMode(bottomRight, OUTPUT);
  pinMode(bottomLeft, OUTPUT);
  pinMode(middle, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  Serial.begin(9600);
  stringKamel.reserve(200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i;
  serialReadFunction();
  if(mode == 1){
    digitalWrite(red, HIGH);
    for(i = 9;i >= 0;i--){
      writeTo7Segment(i);
      delay(1000);
      serialReadFunction();
    }
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    for(i = 9;i >= 0;i--){
      writeTo7Segment(i);
      delay(1000);
      serialReadFunction();
    }
    reset7Segment();
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    delay(1000);
    serialReadFunction();
    delay(1000);
    serialReadFunction();
    digitalWrite(yellow, LOW);
  }else if(mode == 2){
    reset7Segment();
    digitalWrite(green, LOW);
    digitalWrite(red, LOW);
    digitalWrite(yellow, HIGH);
    delay(1000);
    serialReadFunction();
    digitalWrite(yellow, LOW);
    delay(1000);
    serialReadFunction();
  }else if(mode == 3){
    reset7Segment();
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    delay(1000);
    serialReadFunction();
    digitalWrite(red, LOW);
    delay(1000);
    serialReadFunction();
  }
}


void writeTo7Segment(int number){
  reset7Segment();
  if(number == 0){
    digitalWrite(top, HIGH);
    digitalWrite(topRight, HIGH);
    digitalWrite(topLeft, HIGH);
    digitalWrite(bottom, HIGH);
    digitalWrite(bottomRight, HIGH);
    digitalWrite(bottomLeft, HIGH);
  }else if(number == 1){
    digitalWrite(topRight, HIGH);
    digitalWrite(bottomRight, HIGH);
  }else if(number == 2){
    digitalWrite(top, HIGH);
    digitalWrite(topRight, HIGH);
    digitalWrite(middle, HIGH);
    digitalWrite(bottomLeft, HIGH);
    digitalWrite(bottom, HIGH);
  }else if(number == 3){
  digitalWrite(top, HIGH);
  digitalWrite(topRight, HIGH);
  digitalWrite(bottom, HIGH);
  digitalWrite(bottomRight, HIGH);
  digitalWrite(middle, HIGH);
  }else if(number == 4){
  digitalWrite(topRight, HIGH);
  digitalWrite(topLeft, HIGH);
  digitalWrite(bottomRight, HIGH);
  digitalWrite(middle, HIGH);
  }else if(number == 5){
  digitalWrite(top, HIGH);
  digitalWrite(topLeft, HIGH);
  digitalWrite(bottom, HIGH);
  digitalWrite(bottomRight, HIGH);
  digitalWrite(middle, HIGH);
  }else if(number == 6){
  digitalWrite(top, HIGH);
  digitalWrite(topLeft, HIGH);
  digitalWrite(bottom, HIGH);
  digitalWrite(bottomRight, HIGH);
  digitalWrite(bottomLeft, HIGH);
  digitalWrite(middle, HIGH);
  }else if(number == 7){
  digitalWrite(top, HIGH);
  digitalWrite(topRight, HIGH);
  digitalWrite(bottomRight, HIGH);
  }else if(number == 8){
  digitalWrite(top, HIGH);
  digitalWrite(topRight, HIGH);
  digitalWrite(topLeft, HIGH);
  digitalWrite(bottom, HIGH);
  digitalWrite(bottomRight, HIGH);
  digitalWrite(bottomLeft, HIGH);
  digitalWrite(middle, HIGH);
  }else if(number == 9){
  digitalWrite(top, HIGH);
  digitalWrite(topRight, HIGH);
  digitalWrite(topLeft, HIGH);
  digitalWrite(bottom, HIGH);
  digitalWrite(bottomRight, HIGH);
  digitalWrite(middle, HIGH);
  }
}

void reset7Segment(){
  digitalWrite(top, LOW);
  digitalWrite(topRight, LOW);
  digitalWrite(topLeft, LOW);
  digitalWrite(bottom, LOW);
  digitalWrite(bottomRight, LOW);
  digitalWrite(bottomLeft, LOW);
  digitalWrite(middle, LOW);
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


void serialReadFunction(){
  serialKhan();
  if(stringAmade){
    if(stringKamel == "mode1"){
      Serial.println("mode1 selected");
      mode = 1;
    }else if(stringKamel == "mode2"){
      Serial.println("mode2 selected");
      mode = 2;
    }else if(stringKamel == "mode3"){
      Serial.println("mode3 selected");
      mode = 3;
    }
    stringKamel = "";
    stringAmade = false;
  }
}

