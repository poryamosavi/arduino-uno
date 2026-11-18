class Car
{
  public:
    Car(int pin, int color, int maxSpeed, int silandrCount, bool isShassiBoland);
    void startCar();
    void setSpeed(int speed);
    void turnOff();
    int getSpeed();
    void boogh();
  private:
    int _pin;
    int _rang;
    int _taheSorat;
    int _silandrCount;
    int _speed;
    bool _isShassiBoland;
    void speedUp(int speed);
};

Car::Car(int pin, int color, int maxSpeed, int silandrCount, bool isShassiBoland)
{
  _pin = pin;
  _rang = color;
  _taheSorat = maxSpeed;
  _silandrCount = silandrCount;
  _isShassiBoland = isShassiBoland;
  _speed = 0;
  pinMode(_pin, OUTPUT);
}

void Car::startCar()
{
  digitalWrite(_pin, HIGH);
}

void Car::setSpeed(int speed)
{
  if(speed > _taheSorat){
    Serial.println("danger!!!!");
  }else{
    _speed = speed;
  }
}

void Car::turnOff()
{
  digitalWrite(_pin, LOW);
}

int Car::getSpeed()
{
  return _speed;
}

void Car::boogh()
{
  Serial.println("boogh boogh");
}

Car pride(10, 1, 140, 4, 0);
Car bmw(11, 2, 300, 6, 1);

void setup() {
  Serial.begin(9600);
  Serial.println("PRIDE");
  pride.startCar();
  Serial.println(pride.getSpeed());
  pride.setSpeed(90);
  Serial.println(pride.getSpeed());
  pride.setSpeed(200);
  Serial.println(pride.getSpeed());
  pride.boogh();
  delay(2000);
  pride.turnOff();
  Serial.println();
  Serial.println("BMW");
  bmw.startCar();
  Serial.println(bmw.getSpeed());
  bmw.setSpeed(90);
  Serial.println(bmw.getSpeed());
  bmw.setSpeed(200);
  Serial.println(bmw.getSpeed());
  bmw.boogh();
  delay(2000);
  bmw.turnOff();
}

void loop() {
}
