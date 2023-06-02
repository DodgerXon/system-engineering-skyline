#include   <iostream>
// #include <Zumo32U4.h>
// #include <Wire.h>
using namespace std;

#ifndef IMU_H
#define IMU_H
class IMU
{
private:
    string sensor;
public:
    IMU(string);
    void klaarmaken();
    void lezen();
    void printen();
    ~IMU();
};

#endif
