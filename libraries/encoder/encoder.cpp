#include "Arduino.h"
#include "encoder.h"

encoder::encoder(byte ccwPin, byte cwPin, byte btnPin) {
	_ccwPin = ccwPin;
	_cwPin = cwPin;
	pinMode(ccwPin,INPUT);
	pinMode(cwPin,INPUT);	
	_ccwLast = LOW;
	_ccwCurr = LOW;
	
	_btnPin = btnPin;
	_btnLast = LOW;
	_btnCurr = LOW;
	_lastDebounce = 0;
	_debounceDelay = 50;
};

void encoder::check(void (*incCb)(void), void (*decCb)(void)) {
    _ccwCurr = digitalRead(_ccwPin);
    if ((_ccwLast == LOW) && (_ccwCurr == HIGH)) {
        if (digitalRead(_cwPin) == LOW) {
            incCb();
        } else {
            decCb();
        }
    }
    _ccwLast = _ccwCurr;	
};

void encoder::check(void (*incCb)(void), void (*decCb)(void), void (*pushCb)(void)) {
	check(incCb, decCb);
	if(_btnPin < 20) {
		bool r = digitalRead(_btnPin);
		
		if(r != _btnLast) _lastDebounce = millis();
		
		if ((millis() - _lastDebounce) > _debounceDelay) {
			if (r != _btnCurr) {
				_btnCurr = r;
				pushCb();
			}
		};
		_btnLast = r;
	}
}