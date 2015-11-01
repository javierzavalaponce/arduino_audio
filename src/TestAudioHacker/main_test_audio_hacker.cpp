#include <Arduino.h>
#include <Wire.h>

int led = 13;
volatile static unsigned char data[1024];
/*
const unsigned char wav[1024] PROGMEM =
{
0	
};
* 
* 
* ----------------
Device: atmega2560

Program:    4274 bytes (1.6% Full)
(.text + .data + .bootloader)

Data:       1741 bytes (21.3% Full)
(.data + .bss + .noinit)
*/




void setup() {
    pinMode(led, OUTPUT); 
	Serial.begin(115200);
	delay(1000);
	Serial.println("drum javi");

}

void loop() {
	data[0]=12;
	digitalWrite(led, HIGH);   
	delay(1000);
	digitalWrite(led, LOW);
	delay(1000);
}


