#ifndef LIGHT_H
#define LIGHT_H

#include "helper.h"
#include <EEPROM.h> 

#define FRONT_RED A0
#define FRONT_BLUE A1
int v = A1;
#define MAX_INTENSITY 255

enum Light
{
  FrontRed = FRONT_RED,
  FrontBlue = FRONT_BLUE
};

void light_turn_on();
void light_turn_off();

void setup_light();

void set_light(Light light, int intensity);

#endif
