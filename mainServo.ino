#include "BarraBola.h"

#define duration_pwm OCR1A/2

BarraBola* bb;

void setup()
{
  Serial.begin(9600);

  bb = bb_create();
  bb_init();
}

void loop()
{ 
  bb_update(bb);
  delay(100);;
}

