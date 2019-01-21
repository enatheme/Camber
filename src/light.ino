#include "light.h"

void light_turn_on()
{
  //set_light(FrontRed, 255);
  //set_light(FrontBlue, 255);
  digitalWrite(v, 255);
}

void light_turn_off()
{
  //set_light(FrontRed, 0);
  //set_light(FrontBlue, 0);
  digitalWrite(v, 0);
}

void setup_light()
{
  pinMode(v, OUTPUT);
  pinMode(FRONT_BLUE, OUTPUT);
}

void set_light(Light light, int intensity)
{
  intensity %= MAX_INTENSITY;
  digitalWrite(light, intensity);
}
