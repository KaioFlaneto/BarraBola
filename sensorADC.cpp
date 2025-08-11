#include <Arduino.h>
#include <stdlib.h>
#include <math.h>

#include "sensorADC.h"

#define Pin A0

struct sensor
{
  uint16_t value;
  float value_cm;
};

Sensor* sensor_create()
{
  Sensor* sensor = malloc(sizeof(Sensor));
  sensor->value = 0;
  sensor->value_cm = 0.0;

  return sensor;
}

void sensor_init()
{
  ADMUX = 0x40;

  ADCSRA = 0x87;
}

void sensor_read(Sensor* sensor)
{
  ADCSRA |= (1 << ADSC);

  // Espera a conversão terminar
  while (ADCSRA & (1 << ADSC));

  sensor->value = ADCW;
}

uint16_t sensor_value(Sensor* sensor)
{
  return sensor->value;
}

float sensor_value_cm(Sensor* sensor)
{
  float tensao = sensor->value * (5.0/1023.0);
  sensor->value_cm = 12.08 * pow(tensao, -1.058);

  return sensor->value_cm;
}





