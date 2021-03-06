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
  return (double)(analogRead(this->pinX) - dX)/dX;
}

int JoystickMatto::getY() {
  return analogRead(this->pinY);
 }
 
 double JoystickMatto::getYStd() {
  if (this->dY == 0) {
    //this->calibra();
    return this->getY();
  }
  return (double)(analogRead(this->pinY) - dY)/dY;
}

double JoystickMatto::getAngle() {
  double x = this->getXStd();
  double y = this->getYStd();
  double ipo = (double)sqrt(x*x+y*y);
  double algo = (double)acos(x/ipo);
  if (y>=0) {
    return algo;
  }
  return (2*PI) - algo;
}
