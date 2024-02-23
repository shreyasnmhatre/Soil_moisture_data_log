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

    WiFi.begin();

    Wire.begin(ESP32SDA, ESP32SCL);
        if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
        Serial.println(F("SSD1306 allocation failed"));
        while (1);
    }

    Serial.println("> OLED Display Ready");

    display.clearDisplay();
    

    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(1);

    display.setCursor(0, 0);


    display.setCursor(0, 10);
    display.print(F("Moist and Temp"));

    display.display();

    

    display.setCursor(0, 20);
    display.print(F("Value"));

    display.display();

    delay(1000);
}

void loop()
{

    //send byte to the sensor
    sensor.write(byterequest, 8);

    //wait for sensor to reply
    unsigned long resptime = millis();
    while((sensor.available() < sensorFrameSize) && ((millis() - resptime) < sensorWaitingTime)){
        delay(1);
    }

    while (sensor.available()) {
        for (int n = 0; n < sensorFrameSize; n++) {
            byteResponse[n] = sensor.read();
        }

        if (byteResponse[0] != sensorID && byteResponse[1] != sensorFunction && byteResponse[2] != sensorByteResponse) {
            display.clearDisplay();
            display.setCursor(0, 0);
            display.setTextColor(WHITE, BLACK);
            display.print(F("SENSOR FAILED!"));
            display.display();

            return;
        }
    }
    Serial.println();
    Serial.println("Soil Mositure Data:");
    Serial.print("Temperature sensor value");
    Serial.print(temperature);

    String.responseString()
    for(int j =0; j < sensorFrameSize; j++)
    {
        responseString += byteResponse(i) < 0x10 ? " 0":" ";
        resonseString += String(+byteResponse[j],HEX);
        responseString.toUppercase();
        

    }
