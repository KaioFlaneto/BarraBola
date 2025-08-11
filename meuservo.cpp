#include <stdlib.h>
#include <avr/io.h>
#include "meuservo.h"

#define PIN_PWM PB1

void servo_init()
{
  DDRB |= (1 << PB1);  // configura pino 9 como saida

  // zera registradores de controle
  TCCR1A = 0;
  TCCR1B = 0;

  // configurar o modo WGM
  TCCR1A |= (1 << WGM11);
  TCCR1B |= (1 << WGM13) | (1 << WGM12);
  // configura os sinais de saida do pino 9 (PB1)
  TCCR1A |= (1 << COM1A1);
  // diminui a quantidade de contagem
  TCCR1B |= (1 << CS11);
  // duracao do ciclo do timer
  ICR1 = 39999;

  OCR1A = 3000; // equivalente a 1.5ms, pois cada tick do timer vale 2 microsec
}

void servo_set_velocity(int velocity)
{
  if(velocity < -1000) velocity = -100;
  if(velocity >  1000) velocity = 100;

  OCR1A = 3000 + velocity;
}

