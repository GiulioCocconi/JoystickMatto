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
  double algo = (double) -1 * (analogRead(this->pinX) - dX)/dX;
  if (algo > 1.0) {
    return 1.0;
  }
  if (algo < -1.0) {
    return -1.0;
  }
  return algo;
}

int JoystickMatto::getY() {
  return analogRead(this->pinY);
 }
 
 double JoystickMatto::getYStd() {
  if (this->dY == 0) {
    //this->calibra();
    return this->getY();
  }
  double algo = (double)(analogRead(this->pinY) - dY)/dY;
   if (algo > 1.00) {
     return 1.0;
   }
   if (algo < -1.00) {
     return -1.0;
   }
   return algo;
}

double JoystickMatto::getAngle() {
  double x = this->getXStd();
  double y = this->getYStd();
  double ipo = (double)sqrt(x*x+y*y);
  
  if (ipo == 0) {
    return 0;
  }
  
  double algo = (double)acos(x/ipo);
  if (y>=0) {
    return algo;
  }
  return (2*PI) - algo;
}
