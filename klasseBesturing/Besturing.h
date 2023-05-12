#include <iostream>

using namespace std;


class Besturing
{
private:
    char input;
    int snelheidLinks;
    int snelheidRechts;
    /* data */
public:
    Besturing(char i, int sL, int sR);
    ~Besturing();
    void    basicControls();
    void    moveForward();
    void    cornerLeft();
    void    cornerRight();
    void    moveBackwards();
    void    stopMoving();
};


