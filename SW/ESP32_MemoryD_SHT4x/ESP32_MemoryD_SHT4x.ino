
#include <Adafruit_GFX.h>
#include <Adafruit_SharpMem.h>
#include <WiFi.h>
#include "Adafruit_SHT4x.h"

#include "Orbitron_Bold_24.h"
#include "Orbitron_Bold_42.h"
#include "Orbitron_Bold_72.h"

// any pins can be used
#define SHARP_SCK  18
#define SHARP_MOSI 23
#define SHARP_SS   5

Adafruit_SharpMem display(SHARP_SCK, SHARP_MOSI, SHARP_SS, 400, 250);
Adafruit_SHT4x sht4 = Adafruit_SHT4x();

#define BLACK 0
#define WHITE 1
#define uS_TO_S_FACTOR 1000000

void setup(void)
{
  WiFi.mode(WIFI_MODE_NULL);
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);

  float ADC_VALUE = analogRead(34);
  float voltage_value = 0;

  sensors_event_t humidity, temp;
  
  Serial.begin(115200);
  sht4.begin();
  delay(100);
  Serial.println("Hello!");
  sht4.setPrecision(SHT4X_MED_PRECISION);
  //sht4.setHeater(SHT4X_LOW_HEATER_100MS);

  // start & clear the display
  display.begin();
  display.setRotation(0);
  display.clearDisplay();
  delay(100);
  display.setTextColor(BLACK, WHITE);

  sht4.getEvent(&humidity, &temp);
  Serial.print("Temperature: "); Serial.print(temp.temperature); Serial.println(" degrees C");
  Serial.print("Humidity: "); Serial.print(humidity.relative_humidity); Serial.println("% rH");

  display.setFont(&Orbitron_Bold_72);
  display.setCursor(10,70);
  display.println(temp.temperature);
  display.setCursor(10,140);
  display.println(humidity.relative_humidity);

  display.setFont(&Orbitron_Bold_42);
  display.setCursor(10,230);
  voltage_value = (float)((ADC_VALUE * 3.3 ) / (4095))*1.560;
  display.println(voltage_value);

  delay(100);
  display.refresh();
  delay(100);

  esp_sleep_enable_timer_wakeup(1800 * uS_TO_S_FACTOR);
  Serial.flush(); 
  esp_deep_sleep_start();

}

void loop(void) 
{

}
