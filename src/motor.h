#ifndef MOTOR_H
#define MOTOR_H

#include "helper.h"

#define MAX_SPEED 255
#define MIN_SPEED -255

/*
#define FRONT_RIGHT 5
#define FRONT_LEFT 6
#define BACK_RIGHT 7
#define BACK_LEFT 8
*/
// 7 8 12 13

#define FRONT_RIGHT 8
#define FRONT_LEFT 7
#define BACK_RIGHT 12
#define BACK_LEFT 13


enum Wheel {
  FrontRight = FRONT_RIGHT,
  FrontLeft = FRONT_LEFT,
  BackRight = BACK_RIGHT,
  BackLeft = BACK_LEFT
};

enum Side {
  LeftSide = 1,
  RightSide
};

enum Direction {
  Straight = 0,
  LowLeft = -1,
  Left = -2,
  HardLeft = -3,
  LowRight = 1,
  Right = 2,
  HardRight = 3
};

void setup_motor();

void emergency_stop();
void set_speed(Wheel wheel, int speed);
void set_speed(Side side, int speed);

void set_direction_and_speed(int speed, Direction direction);

void test_forward();
void test_backward();
void test_left();
void test_right();

#endif
