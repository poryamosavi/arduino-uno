const int coil1EN = 12;
const int coil1D1 = 11;
const int coil1D2 = 10;

const int coil2EN = 9;
const int coil2D1 = 8;
const int coil2D2 = 7;

const int stepDelay = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(coil1EN, OUTPUT);
  pinMode(coil1D1, OUTPUT);
  pinMode(coil1D2, OUTPUT);
  pinMode(coil2EN, OUTPUT);
  pinMode(coil2D1, OUTPUT);
  pinMode(coil2D2, OUTPUT);

  digitalWrite(coil1EN, LOW);
  digitalWrite(coil2EN, LOW);
}

void loop() {
  digitalWrite(coil1D1, HIGH);
  digitalWrite(coil1D2, LOW);
  digitalWrite(coil2D1, LOW);
  digitalWrite(coil2D2, HIGH);
  digitalWrite(coil1EN, HIGH);
  digitalWrite(coil2EN, HIGH);

  delay(stepDelay);
  
  digitalWrite(coil1D1, HIGH);
  digitalWrite(coil1D2, LOW);
  digitalWrite(coil1EN, HIGH);
  digitalWrite(coil2EN, LOW);

  delay(stepDelay);

  digitalWrite(coil1D1, HIGH);
  digitalWrite(coil1D2, LOW);
  digitalWrite(coil2D1, HIGH);
  digitalWrite(coil2D2, LOW);
  digitalWrite(coil1EN, HIGH);
  digitalWrite(coil2EN, HIGH);

  delay(stepDelay);

  digitalWrite(coil2D1, HIGH);
  digitalWrite(coil2D2, LOW);
  digitalWrite(coil1EN, LOW);
  digitalWrite(coil2EN, HIGH);

  delay(stepDelay);

  digitalWrite(coil1D1, LOW);
  digitalWrite(coil1D2, HIGH);
  digitalWrite(coil2D1, HIGH);
  digitalWrite(coil2D2, LOW);
  digitalWrite(coil1EN, HIGH);
  digitalWrite(coil2EN, HIGH);

  delay(stepDelay);

  digitalWrite(coil1D1, LOW);
  digitalWrite(coil1D2, HIGH);
  digitalWrite(coil1EN, HIGH);
  digitalWrite(coil2EN, LOW);

  delay(stepDelay);

  digitalWrite(coil1D1, LOW);
  digitalWrite(coil1D2, HIGH);
  digitalWrite(coil2D1, LOW);
  digitalWrite(coil2D2, HIGH);
  digitalWrite(coil1EN, HIGH);
  digitalWrite(coil2EN, HIGH);

  delay(stepDelay);

  digitalWrite(coil2D1, LOW);
  digitalWrite(coil2D2, HIGH);
  digitalWrite(coil1EN, LOW);
  digitalWrite(coil2EN, HIGH);

  delay(stepDelay);
}
