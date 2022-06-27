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

#include <Wire.h>
#include <ESP32AnalogRead.h>


ESP32AnalogRead adc;
#define ADCpin 34
#define deviderRatio 1.3
    
void setup() {
  
  // setting ADC
  adc.attach(ADCpin);
  
  Serial.begin(115200);
  delay(100); // let serial console settle

}

void loop() {

  float bat_voltage = adc.readVoltage() * deviderRatio;

  Serial.print("Voltage = " );
  Serial.print(bat_voltage);
  Serial.println("V");

  delay(1000);
}
