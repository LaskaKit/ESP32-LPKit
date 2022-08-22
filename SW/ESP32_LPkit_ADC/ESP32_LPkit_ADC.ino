/*
* Example code for ESP32-LPkit evaluation board made by laskakit.cz
* Firmware sends voltage od pin 34 through serial com port (UART)
* "laskakit.cz" 
* "ESP32 LP-kit"
* The message is sent every second
*
* Created by (c) laskakit.cz 2022
*
* Libraries:
* - ESP32AnalogRead
*/

#include <SPI.h>
#include <Wire.h>
#include <ESP32AnalogRead.h>    // https://github.com/madhephaestus/ESP32AnalogRead

ESP32AnalogRead adc;
#define ADCpin 34
#define deviderRatio 1.7693877551  // Voltage devider ratio on ADC pin 1MOhm + 1.3MOhm
    
void setup() {
    
  Serial.begin(115200);
  delay(100); // let serial console settle
  
  // setting ADC
  adc.attach(ADCpin);
}

void loop() {

  float bat_voltage = adc.readVoltage() * deviderRatio;
  Serial.print("Battery Voltage = " );
  Serial.print(bat_voltage);
  Serial.println("V");

  delay(2000);
}
