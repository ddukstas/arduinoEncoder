#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 2, 18,  17,  16,  15);

#include <encoder.h>
encoder enc(5, 6, 4);

int encoder0Pos = 0;

void incCb() {
    encoder0Pos++;
    lcd.clear();
    lcd.print(encoder0Pos);
}

void decCb() {
    encoder0Pos--;
    lcd.clear();
    lcd.print(encoder0Pos);
}

void pushCb() {
    encoder0Pos = 0;
    lcd.clear();
    lcd.print(encoder0Pos);   
}

void setup() {}

void loop() {
    enc.check(incCb, decCb, pushCb);
}
