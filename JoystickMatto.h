#ifndef __JOYSTICK_h
#define __JOYSTICK_h

#include "Arduino.h"

class JoystickMatto {
    public:     
                JoystickMatto(int, int);
                void calibra();
                int getX();
                int getY();
                double getXStd();
                double getYStd();
    private:    
                int pinX;
                int pinY;
                int dX;
                int dY;
};

#endif
