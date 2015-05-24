# arduinoEncoder
Arduino library for EC11E15244G1 encoder

## methods
* encoder::encoder(byte ccwPin, byte cwPin, byte btnPin)
* void encoder::check(void (*incCb)(void), void (*decCb)(void), void (*pushCb)(void))
