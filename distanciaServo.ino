#include <Servo.h>
#include <HCSR04.h>

HCSR04 sensorDistancia(4 , 5); //trig e echo
float distanceRead = 0;

Servo myServo;

void setup() {
  myServo.attach(2);
  myServo.write(0);
}

void loop() {
  distanceRead = sensorDistancia.dist()/100;
  if(distanceRead < 0.50) {
    myServo.write(0);
  }else{
    myServo.write(180);
  }
  delay(1000);
}
