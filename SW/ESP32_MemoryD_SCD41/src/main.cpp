/*
 * Example code for LaskaKit SCD41 (CO2 sensor) LaskaKit ESP32-lpkit and LaskaKit Memory display
 * 
 * Boards:
 * https://www.laskakit.cz/laskakit-esp32-lpkit-pcb-antenna/
 * https://www.laskakit.cz/laskakit-scd41-senzor-co2--teploty-a-vlhkosti-vzduchu/
 * https://www.laskakit.cz/laskakit-2-7--400x240-lcd-memory-displej/
 * 
 * 
 * Library:
 * https://github.com/sparkfun/SparkFun_SCD4x_Arduino_Library
 * 
 * Made by laskakit.cz (c) 2021
  */

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SharpMem.h>
#include <WiFi.h>
#include "SparkFun_SCD4x_Arduino_Library.h"

#include "Orbitron_Bold_24.h"
#include "Orbitron_Bold_42.h"
#include "Orbitron_Bold_72.h"

// any pins can be used
#define SHARP_SCK  18
#define SHARP_MOSI 23
#define SHARP_SS   5

Adafruit_SharpMem display(SHARP_SCK, SHARP_MOSI, SHARP_SS, 400, 250);


#define BLACK 0
#define WHITE 1
#define uS_TO_S_FACTOR 1000000

SCD4x SCD41;
float ADC_VALUE;
float voltage_value;
uint16_t CO2;
float temperature;
float humidity;

void setup(void) {

  WiFi.mode(WIFI_MODE_NULL);

  ADC_VALUE = analogRead(34);

  Serial.begin(9600);
  Wire.begin();

  //             begin, autoCalibrate
  //               |      |
  if (SCD41.begin(false, true) == false) {
    Serial.println("SCD41 was not set correctly. Check the connection.");
    while (1)
      ;
  }

  if (SCD41.startLowPowerPeriodicMeasurement() == true) {
    Serial.println("Low power mode enabled.");
  }

  // start & clear the display
  display.begin();
  display.setRotation(0);
  display.clearDisplay();

}

void loop(void) {

  while (!SCD41.readMeasurement()) {
    delay(100);
  }

  CO2 = SCD41.getCO2();
  temperature =SCD41.getTemperature();
  humidity = SCD41.getHumidity();

  Serial.println();
  Serial.print("CO2(ppm):");
  Serial.print(CO2);
  Serial.print("\tTemperature(C):");
  Serial.print(temperature, 1);
  Serial.print("\tHumidity(%RH):");
  Serial.print(humidity, 1);
  Serial.println();

  display.setTextColor(BLACK, WHITE);
  display.setFont(&Orbitron_Bold_72);

  display.setCursor(10,62);
  display.println(CO2);

  display.setCursor(10,124);
  display.println(temperature);
  
  display.setCursor(10,186);
  display.println(humidity);

  display.setFont(&Orbitron_Bold_42);
  display.setCursor(10,230);
  voltage_value = (float)((ADC_VALUE * 3.3 ) / (4095))*1.560;
  display.println(voltage_value);

  delay(100);
  display.refresh();
  delay(100);
  
  Serial.print("going to sleep");
  esp_sleep_enable_timer_wakeup(300 * uS_TO_S_FACTOR);
  Serial.flush(); 
  esp_deep_sleep_start();

}
