#ifndef MEUSERVO_H
#define MEUSERVO_H

#include <Arduino.h>

typedef struct servo Servo;

Servo* servo_create();

void servo_destroy(Servo* servo);

void servo_attach(Servo* servo);

void servo_move(Servo* servo, int velocity);

const void servo_update(Servo* servo);

#endif