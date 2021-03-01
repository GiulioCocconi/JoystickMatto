#ifndef __JOYSTICK_h
#define __JOYSTICK_h

#include "Arduino.h"

class JoystickMatto {
    public:     
                JoystickMatto(int pinX, int pinY);
                void calibra(); //Setta i valori dX e dY in modo che il joy risulti una circonferenza centrata sull'intersezione degli assi cartesiani
                int getX(); //Restituisce il valore raw di X
                int getY(); //Restituisce il valore raw di Y
                double getXStd(); //Restituisce il valore di X tenendo conto di dX
                double getYStd(); //Restituisce il valore di Y tenendo conto di dY
                double getAngle(); //Mediante arcos determina l'angolo in radianti tra l'asse x e il punto P di cordinate (X,Y) [Richiede dX e dY]
    private:    
                int pinX;
                int pinY;
                int dX;
                int dY;
};

#endif
