#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "/Users/tkim/Documents/Arduino/libraries/Adafruit_Motor_Shield_V2_Library-master/utility/Adafruit_PWMServoDriver.h"

// set up motor
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *myMotor1 = AFMS.getMotor(1);
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(2);
Adafruit_DCMotor *myMotor3 = AFMS.getMotor(3);
Adafruit_DCMotor *myMotor4 = AFMS.getMotor(4);

byte motorSpeed1;
byte motorSpeed2;
byte motorSpeed3;
byte motorSpeed4;

void setup() {
  Serial.begin(9600);

  // Initialize Motor
  AFMS.begin();
  myMotor1->setSpeed(10);
  myMotor2->setSpeed(10);
  myMotor3->setSpeed(10);
  myMotor4->setSpeed(10);
  myMotor1->run(FORWARD);
  myMotor2->run(FORWARD);
  myMotor3->run(FORWARD);
  myMotor4->run(FORWARD);
}

void loop() {
  delay(10);
  motorSpeed1 = map(analogRead(0), 530, 860, 10, 100);
  motorSpeed2 = 1.1 * motorSpeed1;
  motorSpeed3 = 1.25 * motorSpeed1;
  motorSpeed4 = 1.5 * motorSpeed1;
//  Serial.print(analogRead(0));
//  Serial.print(",");
//  Serial.println(motorSpeed);
  myMotor1->setSpeed(motorSpeed1);
  myMotor2->setSpeed(motorSpeed2);
  myMotor3->setSpeed(motorSpeed3);
  myMotor4->setSpeed(motorSpeed4);
}

