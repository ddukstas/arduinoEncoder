class encoder {
	private:
		byte _ccwPin;
		byte _cwPin;
		bool _ccwLast;
		bool _ccwCurr;
		
		byte _btnPin;
		bool _btnLast;
		bool _btnCurr;
		unsigned long _lastDebounce;
		unsigned int _debounceDelay;
	public:
		encoder(byte ccwPin, byte cwPin, byte btnPin = 255);
		void check(void (*incCb)(void), void (*decCb)(void));
		void check(void (*incCb)(void), void (*decCb)(void), void (*pushCb)(void));
};