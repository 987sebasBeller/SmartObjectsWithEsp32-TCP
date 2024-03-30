#include "UltrasonicSensor.h"
UltrasonicSensor::UltrasonicSensor(byte triggerPin, byte echoPin)
{
  this->triggerPin = triggerPin;
  this->echoPin = echoPin;
}
long UltrasonicSensor::readDistance()
{
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}
int UltrasonicSensor::getTheShortestDistance(byte sampleSize)
{
  int cmMin = INT_MAX;
  int cm = 0;
  for (byte i = 0; i < sampleSize; i++)
  {
    cm = 0.01723 * readDistance();
    cmMin = min(cm, cmMin);
  }
  return cmMin;
}
UltrasonicSensor::~UltrasonicSensor()
{
}