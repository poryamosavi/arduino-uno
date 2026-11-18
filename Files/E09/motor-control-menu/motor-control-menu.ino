void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);

  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
  clearScreen();
}

int motorDirection = 0;
String userInput;
int menuNumber = 0;
char userChoice = 0;
int userInteger = 0;
int motorSpeed = 255;

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hi there, what is your name?");

  while(menuNumber == 0){
    while(Serial.available()){
      userInput = Serial.readString();
      menuNumber = 1;
    }
  }
  clearScreen();
  Serial.print("Hello ");
  Serial.print(userInput);
  Serial.println(", nice to meet you!");
  delay(2000);
  clearScreen();

  showMenu1();
}


void turnMotorOn(){
  analogWrite(3, motorSpeed);
}
void turnMotorOff(){
  analogWrite(3, 0);
}
void ChangeMotorDirection(){
  if(motorDirection == 0){
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    motorDirection = 1;
  }else{
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    motorDirection = 0;
  }
}
void showMenu1(){
  Serial.println("What can I do for you?");
  Serial.println("1.Turn on motor");
  Serial.println("2.Turn off motor");
  Serial.println("3.Change motor direction");
  Serial.println("4.Enter Speed");

  while(menuNumber == 1){
    while(Serial.available()){
      userChoice = Serial.read();
      if(userChoice == '1'){
        turnMotorOn();
      }else if(userChoice == '2'){
        turnMotorOff();
      }else if(userChoice == '3'){
        ChangeMotorDirection();
      }else if(userChoice == '4'){
        menuNumber = 2;
        clearScreen();
        showMenu2();
      }else{
        Serial.println("Error! Wrong input!");
      }
      clearScreen();
      showMenu1();
    }
  }
}
void clearScreen(){
  Serial.print("\033[0H\033[0J");
}
void showMenu2(){
  Serial.println("Please enter motor speed :");

  while(menuNumber == 2){
    while(Serial.available()){
      userInteger = Serial.parseInt();
      if(userInteger > 255){
        Serial.println("Error! Motor speed should not be greater than 255");
        delay(2000);
      }else if(userInteger < 0){
        Serial.println("Error! Motor speed should not be less than 0");
        delay(2000);
      }else{
        Serial.print("You entered: ");
        Serial.println(userInteger);
        motorSpeed = userInteger;
        turnMotorOn();
      }
      clearScreen();
      menuNumber = 1;
      showMenu1();
    }
  }
}

