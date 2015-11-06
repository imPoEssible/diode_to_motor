#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "/Users/tkim/Documents/Arduino/libraries/Adafruit_Motor_Shield_V2_Library-master/utility/Adafruit_PWMServoDriver.h"

// set up motor
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *myMotor1 = AFMS.getMotor(1);

int wow;
void setup() {
  Serial.begin(9600);

  // Initialize Motor
  AFMS.begin();
  myMotor1->run(FORWARD);
  myMotor1->setSpeed(10);
  
}

void loop() {
  delay(10);
  wow = (analogRead(0)-530)/5 +30;
  Serial.print(analogRead(0));
  Serial.print(",");
  Serial.println(wow);
  myMotor1->setSpeed(wow);

}

