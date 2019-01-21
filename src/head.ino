#include "head.h"

void say_yes()
{
  Serial.println("say yes");
  BOTTOM_MIDDLE
  delay(200);
  for (int i = 0 ; i < 3 ; ++i) {
    TOP_MIDDLE
    delay(100);
    BOTTOM_MIDDLE
    delay(100);
  }
}

void say_no()
{
  Serial.println("say no");
  BOTTOM_MIDDLE
  delay(200);
  for (int i = 0 ; i < 3 ; ++i) {
    BOTTOM_RIGHT
    delay(100);
    BOTTOM_LEFT
    delay(100);
  }
}

// speed will reduce the rotation speed, see it later
// speed how long we wait to inc
void set_cam(int h_pos, int v_pos, int speed)
{
  //DEBUG("set cam");
  if (h_pos > horizontal.read()) {
    //DEBUG("horizontal increase");
    increase_servo(horizontal.read(), h_pos, horizontal, speed);
  }
  else if (h_pos < horizontal.read()) {
    //DEBUG("horizontal decrease");
    decrease_servo(horizontal.read(), h_pos, horizontal, speed);    
  }
  
  if (v_pos > vertical.read()) {
    //DEBUG("vertical increase");
    increase_servo(vertical.read(), v_pos, vertical, speed);
  }
  else if (v_pos < vertical.read()) {
    //DEBUG("vertical decrease");
    decrease_servo(vertical.read(), v_pos, vertical, speed);    
  }
}

void move_cam(int deviation, int speed, bool horizontal_plan)
{
}

void increase_servo(int from, int to, Servo & servo, int speed)
{
  for ( ; from <= to ; ++from) {
    servo.write(from);
    delay(speed);
  }
}

void decrease_servo(int from, int to, Servo & servo, int speed)
{
  for ( ; from >= to ; --from) {
    servo.write(from);
    delay(speed);
  }
}

void setup_head()
{
  horizontal.attach(HORIZONTAL_PIN);
  vertical.attach(VERTICAL_PIN);
  horizontal.write(90);
  vertical.write(0);
}
