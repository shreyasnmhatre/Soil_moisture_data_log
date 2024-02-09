#include <Arduino.h>
#include <FireBaseESP>

#define WIFI_SSID                   ""
#define WIFI_PASSWORD               ""

// Sensor Pin Definition 
#define RS485Power                  18
#define RS485RX                     23
#define RS485TX                     22


void setup(){
    Serial.begin(9600);

    pinMode(displayPower,OUTPUT);
    pinMode(RS485Power,OUTPUT);

    digitalWrite(displayPower, HIGH);
    digitalWrite(RS485Power, HIGH);

    
}