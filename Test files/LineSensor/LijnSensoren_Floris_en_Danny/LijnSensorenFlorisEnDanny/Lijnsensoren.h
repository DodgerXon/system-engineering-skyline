#include <QTRSensors.h>

class Lijnsensoren : public QTRSensors {
    
    public:
    void readCalibrated(unsigned int, unsigned char);


    private:
    int sensorwaardes;
    char iets;


};