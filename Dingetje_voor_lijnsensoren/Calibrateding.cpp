void QTRSensors::calibrate(int& kleurmin, int& kleurmax)
{
    if(readMode == QTR_EMITTERS_ON_AND_OFF || readMode == QTR_EMITTERS_ON)
    {
        calibrateOnOrOff(kleurmin == &calibratedMinimumOn,
                         kleurmax == &calibratedMaximumOn,
                         QTR_EMITTERS_ON);
    }


    if(readMode == QTR_EMITTERS_ON_AND_OFF || readMode == QTR_EMITTERS_OFF)
    {
        calibrateOnOrOff(kleurmin == &calibratedMinimumOff,
                         kleurmax == &calibratedMaximumOff,
                         QTR_EMITTERS_OFF);
    }
}