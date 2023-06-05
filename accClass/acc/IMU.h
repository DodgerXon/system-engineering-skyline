#include "Arduino.h"
#include <Zumo32U4.h>
#include <Wire.h>
using namespace std;

#ifndef IMU_H
#define IMU_H
class IMU 
{
private:
    String sens;
public:
    IMU();
    void klaarmaken();
    void lezen();
    void printen();
    void balans();
    ~IMU();
};

#endif
