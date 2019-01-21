#include "main.h"

void setup() {
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  //setup_com();
  setup_head();
  setup_motor();
  setup_light();
  Serial.begin(115200);
  Serial.println("HELP");
}

void loop() {
  return;
  Serial.println("FORWARD");
  test_forward();
  delay(200000);
  Serial.println("BACKWARD");
  test_backward();
  delay(2000);
  return;
  test_left();
  delay(2000);
  test_right();
  delay(2000);
  return;
  Serial.println("FRONT LEFT");
  set_speed(FrontLeft, 50);
  delay(2000);
  set_speed(FrontLeft, 0);
  Serial.println("BACK LEFT");
  set_speed(BackLeft, 50);
  delay(2000);
  set_speed(BackLeft, 0);
  Serial.println("FRONT RIGHT");
  set_speed(FrontRight, 50);
  delay(2000);
  set_speed(FrontRight, 0);
  Serial.println("BACK RIGHT");
  set_speed(BackRight, 50);
  delay(2000);
  set_speed(BackRight, 0);
  delay(2000);
  Serial.println("OFF");
}
