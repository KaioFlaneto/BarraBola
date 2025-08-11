#ifndef SENSOR_DISTANCIA_H
#define SENSOR_DISTANCIA_H

typedef struct sensor Sensor;

Sensor* sensor_create();

void sensor_init();

void sensor_read(Sensor* sensor);

uint16_t sensor_value(Sensor* sensor);

float sensor_value_cm(Sensor* sensor);

#endif