#include "meuservo.h"
#include "sensorADC.h"


void setup()
{
  Serial.begin(9600);

  meu_servo_init();
}

void loop()
{ 
  Serial.print("Duration_pwm: ");
  Serial.println(servo_get_duration_pwm());
  servo_set_velocity(100);
  Serial.print("Duration_pwm: ");
  Serial.println(servo_get_duration_pwm());
  delay(1000);

  servo_set_velocity(50);
  Serial.print("Duration_pwm: ");
  Serial.println(servo_get_duration_pwm());
  delay(1000);
}

