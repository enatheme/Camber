#ifndef HEAD_H
#define HEAD_H

#include "helper.h"

#include <Servo.h>
#include <EEPROM.h> 

#define HORIZONTAL_PIN A4
#define VERTICAL_PIN A5

#define H_MIN = 0
#define H_MAX = 90
#define V_MIN = 0
#define V_MAX = 180

#define TOP_LEFT      set_cam(0, 90, 5);
#define TOP_RIGHT     set_cam(180, 90, 5);
#define TOP_MIDDLE    set_cam(90, 90, 5);
#define BOTTOM_LEFT   set_cam(0, 0, 5);
#define BOTTOM_RIGHT  set_cam(180, 0, 5);
#define BOTTOM_MIDDLE set_cam(90, 0, 5);

Servo vertical;
Servo horizontal;

void setup_head();

void say_yes();
void say_no();

void set_cam(int h_pos, int v_pos, int speed = 1);
void move_cam(int deviation, int speed, bool horizontal_plan);

void increase_servo(int from, int to, Servo & servo, int speed = 1);
void decrease_servo(int from, int to, Servo & servo, int speed = 1);

#endif
