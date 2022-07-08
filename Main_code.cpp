//Pin numbers definition
const int motorEnableLeft = 9;
const int motorForwardLeft = 7;
const int motorBackLeft = 8;
const int motorEnableRight = 11;
const int motorForwardRight = 12;
const int motorBackRight = 10;
const int trigPinFront = A1;
const int echoPinFront = 2;
const int trigPinLeft = 3;
const int echoPinLeft = 4;
const int trigPinRight = 5;
const int echoPinRight = 6;
const int irPin = A0;

//Variables for the Motors
const int leftMotorSpeed = 160; //best at 160
const int rightMotorSpeed = 255;//best at 255
const int delayTime = 150;

//Variables for Ultrasonic Sensors
long durationFront;
int distanceFront;
long durationLeft;
int distanceLeft;
long durationRight;
int distanceRight;
const int minFrontDistance = 30;
const int minSideDistance = 20;
const int stuckDistance = 10;

//Variables for IR Sensor
#include <IRremote.h>
IRrecv irrecv(irPin);
decode_results results;
boolean onoff = 0;
//Control IR numbers
const long PLAY = 16761405;
const long PREV = 16720605;

void stopCar () {
  digitalWrite(motorForwardLeft, LOW);
  digitalWrite(motorBackLeft, LOW);
  digitalWrite(motorForwardRight, LOW);
  digitalWrite(motorBackRight, LOW);
  analogWrite(motorEnableLeft, 0);
  analogWrite(motorEnableRight, 0);
}

void goForwardFull () {
  digitalWrite(motorForwardLeft, HIGH);
  digitalWrite(motorBackLeft, LOW);
  digitalWrite(motorForwardRight, HIGH);
  digitalWrite(motorBackRight, LOW);
  analogWrite(motorEnableLeft, leftMotorSpeed);
  analogWrite(motorEnableRight, rightMotorSpeed);
}

void goLeft () {
  digitalWrite(motorForwardLeft, LOW);
  digitalWrite(motorBackLeft, LOW);
  digitalWrite(motorForwardRight, HIGH);
  digitalWrite(motorBackRight, LOW);
  analogWrite(motorEnableLeft, 0);
  analogWrite(motorEnableRight, rightMotorSpeed);
}

void goRight () {
  digitalWrite(motorForwardLeft, HIGH);
  digitalWrite(motorBackLeft, LOW);
  digitalWrite(motorForwardRight, LOW);
  digitalWrite(motorBackRight, LOW);
  analogWrite(motorEnableLeft, leftMotorSpeed);
  analogWrite(motorEnableRight, 0);
}

void goBack () {
  digitalWrite(motorForwardLeft, LOW);
  digitalWrite(motorBackLeft, HIGH);
  digitalWrite(motorForwardRight, LOW);
  digitalWrite(motorBackRight, HIGH);
  analogWrite(motorEnableLeft, leftMotorSpeed);
  analogWrite(motorEnableRight, rightMotorSpeed);
}

void sensorRead () {
  //Read front sensor value
  digitalWrite(trigPinFront, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinFront, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinFront, LOW);
  durationFront = pulseIn(echoPinFront, HIGH);
  distanceFront = durationFront * 0.034 / 2;
  //Read left sensor value
  digitalWrite(trigPinLeft, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinLeft, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinLeft, LOW);
  durationLeft = pulseIn(echoPinLeft, HIGH);
  distanceLeft = durationLeft * 0.034 / 2;
  //Read right sensor value
  digitalWrite(trigPinRight, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinRight, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinRight, LOW);
  durationRight = pulseIn(echoPinRight, HIGH);
  distanceRight = durationRight * 0.034 / 2;
}


void setup() {
  pinMode(motorEnableLeft, OUTPUT);
  pinMode(motorForwardLeft, OUTPUT);
  pinMode(motorBackLeft, OUTPUT);
  pinMode(motorEnableRight, OUTPUT);
  pinMode(motorForwardRight, OUTPUT);
  pinMode(motorBackRight, OUTPUT);
  pinMode(trigPinFront, OUTPUT);
  pinMode(echoPinFront, INPUT);
  pinMode(trigPinLeft, OUTPUT);
  pinMode(echoPinLeft, INPUT);
  pinMode(trigPinRight, OUTPUT);
  pinMode(echoPinRight, INPUT);
  irrecv.enableIRIn();
}

void loop() {
  sensorRead();
  if (irrecv.decode(&results)) {
    irrecv.resume();
    if (results.value == PLAY)
      onoff = 1;
    else if (results.value == PREV)
      onoff = 0;
  }
  if (onoff == 1) {
    results.value = 0;
    if ((distanceFront <= minFrontDistance) || (distanceLeft <= minSideDistance) || (distanceRight <= minSideDistance)) {
      if ((distanceLeft < stuckDistance) || (distanceRight < stuckDistance) || (distanceFront < stuckDistance)) {
        goBack();
        delay(1.5*delayTime);
      }
      else if ((distanceFront <= minFrontDistance) && (distanceLeft <= minSideDistance) && (distanceRight <= minSideDistance)) {
        goBack();
        delay(1.5*delayTime);
      }
      else if (distanceLeft > distanceRight ) {
        goLeft();
        delay(delayTime);
      }
      else if (distanceLeft <= distanceRight) {
        goRight();
        delay(delayTime);
      }
      else
        goForwardFull();
    }
    else
      goForwardFull();
  }
  else if (onoff == 0) {
    results.value = 0;
    stopCar();
  }
}