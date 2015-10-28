#include <Arduino.h>
#include <Wire.h>

int led = 13;

void setup() {
    pinMode(led, OUTPUT); 
	Serial.begin(115200);
	delay(1000);
}

void loop() {
	digitalWrite(led, HIGH);   
	delay(1000);
	digitalWrite(led, LOW);
	delay(1000);
}


