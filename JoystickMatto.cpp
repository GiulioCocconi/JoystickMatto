#include "JoystickMatto.h"

JoystickMatto::JoystickMatto(int pinX, int pinY) {
  this->pinX = pinX;
  this->pinY = pinY;
  this->dX = 0;
  this->dY = 0;
}

void JoystickMatto::calibra() {
  delay(1000);
  this->dX = -1 * analogRead(pinX);
  this->dY = -1 * analogRead(pinY);
 }
 
int JoystickMatto::getX() {
  return analogRead(this->pinX);
 }
 
double JoystickMatto::getXStd() {
  return (double)(analogRead(this->pinX) + dX)/-dX;
}

int JoystickMatto::getY() {
  return analogRead(this->pinY);
 }
 
 double JoystickMatto::getYStd() {
  return (double)(analogRead(this->pinY) + dY)/-dY;
}
