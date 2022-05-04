/*
* Vzorovy kod od laskarduino.cz pro SCD41 s vyvojovym kitem ESP32-LPkit
* Kod posle pres seriovy port (UART) a zaroven na server TMEP.cz
* hodnoty teploty a vlhkosti z SCD41
* kazdou minutu
*
* SHT40 (https://www.laskakit.cz/laskakit-scd41-senzor-co2--teploty-a-vlhkosti-vzduchu/) je pripojen pres uSup konektor
* ESP32-LPkit (https://www.laskakit.cz/laskakit-esp32-lpkit-pcb-antenna/)
*
* Vytvoreno (c) laskarduino.cz 2022
*
* Potrebne knihovny:
* https://github.com/sparkfun/SparkFun_SCD4x_Arduino_Library
*/

#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>
#include "SparkFun_SCD4x_Arduino_Library.h"

const char* ssid = "SSID";
const char* password = "PASSWORD";

// SCD41
SCD4x SCD41;

// vypln tvou domenu, kterou sis zaregistroval na tmep.cz
String serverName = "http://TVOJEDOMENA.tmep.cz/index.php?";
 
void setup() {
  Serial.begin(115200);
  Wire.begin();

  delay(10);
  while (!Serial) 
  {
    ; // cekani na Serial port
  }

  // inicializace
  //             begin, autoCalibrate
  //               |      |
  if (SCD41.begin(false, true) == false)
  {
    Serial.println("SCD41 nenalezen");
    Serial.println("Zkontroluj propojeni");
    while(1)
      ;
  }
 
  // prepnuti do low power modu
  if (SCD41.startLowPowerPeriodicMeasurement() == true)  
  {
    Serial.println("Low power mode enabled.");
  }

  WiFi.begin(ssid, password);
  Serial.println("Pripojovani");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Pripojeno do site, IP adresa zarizeni: ");
  Serial.println(WiFi.localIP());
}
 
void loop() {
  while (!SCD41.readMeasurement()) // cekani na nova data (zhruba 30s)
  {
    delay(1);
  } 

  // odeslani hodnot pres UART
  Serial.print("Teplota: "); Serial.print(SCD41.getTemperature()); Serial.println(" degC");
  Serial.print("Vlhkost: "); Serial.print(SCD41.getHumidity()); Serial.println("% rH");
  Serial.print("CO2: "); Serial.print(SCD41.getCO2()); Serial.println(" ppm");

  // odeslani hodnot na TMEP.cz
  if(WiFi.status()== WL_CONNECTED)
  {
      HTTPClient http;
      
      //GUID pro teplotu "teplota", pro vlhkost "humV", pro CO2 "CO2"
      String serverPath = serverName + "teplota=" + SCD41.getTemperature() + "&humV=" + SCD41.getHumidity() + "&CO2=" + SCD41.getCO2(); 
      
      // zacatek http spojeni
      http.begin(serverPath.c_str());
      
      // http get request
      int httpResponseCode = http.GET();
      
      if (httpResponseCode>0) 
      {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        String payload = http.getString();
        Serial.println(payload);
      }
      else 
      {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }
      // Free resources
      http.end();
    }
    else 
    {
      Serial.println("Wi-Fi odpojeno");
    }

  delay(60000);
}
