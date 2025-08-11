#include <Arduino.h>

#include "BarraBola.h"

#include "sensorADC.h"
#include "meuservo.h"

struct barrabola
{
  float target;
  int Kp, Ki, Kd;
  Sensor* sensor;
};

BarraBola* bb_create()
{
  BarraBola* bb = malloc(sizeof(BarraBola));
  bb->target = 0.0;
  bb->Kp = 1.0;
  bb->Ki = 1.0;
  bb->Kd = 1.0f;

  bb->sensor = sensor_create();

  return bb;
}

void bb_delete(BarraBola* bb)
{
  sensor_delete(bb->sensor);
  free(bb);
}

void bb_init()
{
  sensor_init();
  servo_init();
}

void bb_set_target(BarraBola* bb, float target)
{
  bb->target = target;
}

void bb_update(BarraBola* bb)
{
  sensor_read(bb->sensor);

  uint16_t value = sensor_get_value(bb->sensor);
  servo_set_velocity(value);
  Serial.print("Sensor adc: ");
  Serial.println(value);
}


