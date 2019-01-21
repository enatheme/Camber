#include "motor.h"

void test_forward()
{
  analogWrite(FRONT_RIGHT, HIGH);
  digitalWrite(FRONT_LEFT, HIGH);
  analogWrite(BACK_RIGHT, HIGH);
  digitalWrite(BACK_LEFT, HIGH);
}
void test_backward()
{
  //analogWrite(FRONT_RIGHT, -40);
  //analogWrite(FRONT_LEFT, 40);
  //analogWrite(BACK_RIGHT, 40);
  //analogWrite(BACK_LEFT, 40);
}
void test_left()
{
  analogWrite(FRONT_RIGHT, 40);
  analogWrite(FRONT_LEFT, 0);
  analogWrite(BACK_RIGHT, 0);
  analogWrite(BACK_LEFT, 40);
}
void test_right()
{
  analogWrite(FRONT_RIGHT, 0);
  analogWrite(FRONT_LEFT, 40);
  analogWrite(BACK_RIGHT, 40);
  analogWrite(BACK_LEFT, 0);
}

void setup_motor()
{
  pinMode(FRONT_RIGHT, OUTPUT);
  pinMode(FRONT_LEFT, OUTPUT);
  pinMode(BACK_RIGHT, OUTPUT);
  pinMode(BACK_LEFT, OUTPUT);
}

void emergency_stop()
{
  analogWrite(FRONT_RIGHT, 0);
  analogWrite(FRONT_LEFT, 0);
  analogWrite(BACK_RIGHT, 0);
  analogWrite(BACK_LEFT, 0);
}

void set_speed(Wheel wheel, int speed)
{
  //speed %= MAX_SPEED;
  //speed %= MIN_SPEED;
  //digitalWrite(wheel, speed);
  analogWrite(wheel, speed);
}

void set_speed(Side side, int speed)
{
  switch (side)
  {
    case LeftSide:
      set_speed(FrontLeft, speed);
      set_speed(BackLeft, speed);
    break;
    case RightSide:
      set_speed(FrontRight, speed);
      set_speed(BackRight, speed);
    break;
  }
}

void set_direction_and_speed(int speed, Direction direction)
{
  switch (direction)
  {
    case Straight:
      set_speed(LeftSide, speed);
      set_speed(RightSide, speed);
    break;
    case LowLeft:
      set_speed(LeftSide, speed * 0.25);
      set_speed(RightSide, speed);
    break;
    case Left:
      set_speed(LeftSide, 0);
      set_speed(RightSide, speed);
    break;
    case HardLeft:
      set_speed(LeftSide, -speed);
      set_speed(RightSide, speed);
    break;
    case LowRight:
      set_speed(LeftSide, speed);
      set_speed(RightSide, speed * 0.25);
    break;
    case Right:
      set_speed(LeftSide, speed);
      set_speed(RightSide, 0);
    break;
    case HardRight:
      set_speed(LeftSide, speed);
      set_speed(RightSide, -speed);
    break;
  }
}
