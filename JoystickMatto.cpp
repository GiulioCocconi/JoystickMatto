#include "JoystickMatto.h"

JoystickMatto::JoystickMatto(int pinX, int pinY) {
  this->pinX = pinX;
  this->pinY = pinY;
  this->dX = 0;
  this->dY = 0;
}

void JoystickMatto::calibra() {
  delay(1000);
  this->dX = analogRead(this->pinX);
  this->dY = analogRead(this->pinY);
 }
 
int JoystickMatto::getX() {
  return analogRead(this->pinX);
 }

 
double JoystickMatto::getXStd() {
  if (this->dX == 0) {
    //this->calibra();
    return this->getX();
  }
  return (double) -1 * (this->getX() - dX)/dX;
}

int JoystickMatto::getY() {
  return analogRead(this->pinY);
 }
 
 double JoystickMatto::getYStd() {
  if (this->dY == 0) {
    //this->calibra();
    return this->getY();
  }
  return (double)(this->getY() - dY)/dY;
}

double JoystickMatto::getAngle() {
  double x = this->getXStd();
  double y = this->getYStd();
  double ipo = (double)sqrt(x*x+y*y);
  double algo = (double)acos(x/ipo);
  if (x == 0 && y == 0) {
    return 0;
  }
  if (y>=0) {
    return algo;
  }
  return (2*PI) - algo;
}
