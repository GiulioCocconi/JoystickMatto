#include "JoystickMatto.h"

JoystickMatto::JoystickMatto(int pinX, int pinY) {
  this->pinX = pinX;
  this->pinY = pinY;
  this->dX = 0;
  this->dY = 0;
}

void JoystickMatto::calibra() {
  delay(1000);
  this->dX = -1 * analogRead(this->pinX);
  this->dY = -1 * analogRead(this->pinY);
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

double JoystickMatto::getAngle() {
  double x = this->getXStd();
  double y = this->getYStd();
  double ipo = sqrt(x*x+y*y);
  return acos(x/ipo);
}
