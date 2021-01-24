#ifndef __JOYSTICK_h
#define __JOYSTICK_h

#include "Arduino.h"

class Joystick {
    public:     
                Joystick(int, int, int);
                void calibra();
                int getX();
                int getY();
                int getXStd();
                int getYStd();
    private:    
                int pinX;
                int pinY;
                int dX;
                int dY;
};

#endif
