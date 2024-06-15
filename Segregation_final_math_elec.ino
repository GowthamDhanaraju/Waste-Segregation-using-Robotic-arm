#include <Servo.h>

Servo gripper; //gripper
Servo elbow;
Servo base;
void setup() {
  Serial.begin(9600);
  gripper.attach(3);
  elbow.attach(9);
  base.attach(10);
}

void loop() {
  elbow.write(180);
  delay(1000);
  base.write(90);
  delay(1000);
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();  // Remove any leading/trailing whitespace
    if (command == "recycle") {
      pick();
      place1();
      }
    else if (command == "non-recycle") {
      pick();
      place2();
      }
    else if (command == "reset") {
      exit(0);
    }
  }
  gripper.write(90);
  exit(0);
}
void pick(){
  elbow.write(90);
  delay(2000);
  gripper.write(0);
  delay(1000);
}
void place1(){
  base.write(180);
  delay(1000);
  elbow.write(180);
  delay(1000);
  gripper.write(20);
  delay(1000);
}
void place2(){
  base.write(0);
  delay(1000);
  elbow.write(180);
  delay(1000);
  gripper.write(20);
  delay(1000);
}
void ret(){
  elbow.write(90);
  delay(1000);
  base.write(90);
  delay(1000);
  elbow.write(180);
  delay(1000);

}