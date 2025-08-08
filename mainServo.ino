#include "meuservo.h"

#define pinoTrig 5
#define pinoEcho 6

Servo* servo;

long duracao;
int distancia;

void setup()
{
  Serial.begin(9600);

  servo = servo_create();
  servo_attach(servo);
  servo_move(servo, 50);

  pinMode(pinoTrig, OUTPUT);
  // Configura o pino de Echo como ENTRADA
  pinMode(pinoEcho, INPUT);
}

void loop()
{
  servo_update(servo);

  digitalWrite(pinoTrig, LOW);
  delayMicroseconds(2);

  digitalWrite(pinoTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinoTrig, LOW);

  duracao = pulseIn(pinoEcho, HIGH);

  distancia = duracao * 0.0343 / 2;

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  servo_move(servo, distancia);

}
