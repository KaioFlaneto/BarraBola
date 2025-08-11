#ifndef SENSOR_DISTANCIA_H
#define SENSOR_DISTANCIA_H

// GP2Y0A41SK0F 4cm a 30cm
// valores de ADC entre 0 a 634 aproximadamente (0.1V a 3.1V)

#define sensor_min_voltage 0.1
#define sensor_max_voltage 3.1

typedef struct sensor Sensor;

Sensor* sensor_create();

void sensor_delete(Sensor* sensor);

void sensor_init();

void sensor_read(Sensor* sensor);

uint16_t sensor_get_value(Sensor* sensor);

float sensor_get_value_cm(Sensor* sensor);

#endif