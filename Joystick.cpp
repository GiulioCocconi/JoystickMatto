#include "Joystick.h"

Joystick::Joystick(int pinX, int pinY) {
  this->pinX = pinX;
  this->pinY = pinY;
  this.calibra();
}

void Joystick::calibra() {
  delay(1000);
  this->dX = -1 * analogRead(pinX);
  this->dY = -1 * analogRead(pinY);
 }
 
int Joystick::getX() {
  return analogRead(this->pinX);
 }
 
double Joystick::getXStd() {
  return (double)(analogRead(this->pinX) + dX)/dX
}

int Joystick::getY() {
  return analogRead(this->pinY);
 }
 
 double Joystick::getYStd() {
  return (double)(analogRead(this->pinY) + dY)/dY
}
