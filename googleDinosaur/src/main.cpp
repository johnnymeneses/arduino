#include <Arduino.h>
#include <Servo.h>

Servo servo_2;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);

  servo_2.attach(2);

}

void loop()
{
  Serial.println(analogRead(A0));
  if (analogRead(A0) < 300) {
    servo_2.write(60);
    delay(150); // Wait for 150 millisecond(s)
  } else {
    servo_2.write(0);
  }
}
