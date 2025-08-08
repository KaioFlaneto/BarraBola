#include <stdlib.h>
#include "meuservo.h"

#define PIN_PWM PB1
#define FREQ_PWM 20000 // 20 ms em microsec

struct servo
{
  int velocity;            // velocidade -100 a 100
  unsigned long last_time; // tempo ultimo pulso
};

Servo* servo_create()
{
  Servo* servo = malloc(sizeof(Servo));
  servo->velocity = 0;
  servo->last_time = 0;

  return servo;
}

void servo_destroy(Servo* servo)
{
  free(servo);
}

void servo_attach(Servo* servo)
{
  DDRB |= (1 << PIN_PWM); // PINO 9 OUTPUT
  servo->last_time = micros();
}

void servo_move(Servo* servo, int velocity)
{
  if(velocity < -100) velocity = -100;
  if(velocity >  100) velocity = 100;

  servo->velocity = velocity;
}

const void servo_update(Servo* servo)
{
  unsigned long current_time = micros();
  if((current_time - servo->last_time) < FREQ_PWM)
  {
    return;
  }

  servo->last_time = current_time;

  unsigned long duration_pwm = 1500 + (servo->velocity*5);
  
  PORTB |= (1 << PIN_PWM);
  unsigned long start_pulse = micros();
  while((micros() - start_pulse) < duration_pwm);
  PORTB &= ~(1 << PIN_PWM);

  return;
}