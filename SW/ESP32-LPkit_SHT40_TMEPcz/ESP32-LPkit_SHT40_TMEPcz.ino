/*
* Vzorovy kod od laskakit.cz pro SHT40 s vyvojovym kitem ESP32-LPkit
* Kod posle pres seriovy port (UART) a zaroven na server TMEP.cz
* hodnoty teploty a vlhkosti z SHT40 kazdou minutu
*
* SHT40 (https://www.laskakit.cz/laskakit-sht40-senzor-teploty-a-vlhkosti-vzduchu/) je pripojen pres uSup konektor
* ESP32-LPkit (https://www.laskakit.cz/laskakit-sht40-senzor-teploty-a-vlhkosti-vzduchu/)
*
* Vytvoreno (c) laskakit.cz 2022
*
* Potrebne knihovny:
* https://github.com/adafruit/Adafruit_SHT4X
*/

#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>
#include "Adafruit_SHT4x.h"
 
const char* ssid = "SSID";
const char* password = "PASSWORD";

Adafruit_SHT4x sht4 = Adafruit_SHT4x();

// vypln tvou domenu cidla, kterou sis zaregistroval na tmep.cz
String serverName = "http://TVADOMENA.tmep.cz/index.php?";
 
void setup() {
  Serial.begin(115200);
  while (!Serial) 
  {
    ; // cekani na Serial port
  }
 
  if (! sht4.begin()) 
  {
    Serial.println("SHT4x nenalezen");
    Serial.println("Zkontroluj propojeni");
    while (1) delay(1);
  }
 
  sht4.setPrecision(SHT4X_HIGH_PRECISION); // nejvyssi rozliseni
  sht4.setHeater(SHT4X_NO_HEATER); // bez vnitrniho ohrevu
 
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
  sensors_event_t humidity, temp; // promenne vlhkost a teplota
 
  // cteni teploty
  sht4.getEvent(&humidity, &temp);
  // odeslani hodnot pres UART
  Serial.print("Teplota: "); Serial.print(temp.temperature); Serial.println(" degC");
  Serial.print("Vlhkost: "); Serial.print(humidity.relative_humidity); Serial.println("% rH");
 
  // odeslani hodnot na TMEP.cz
  if(WiFi.status()== WL_CONNECTED){
      HTTPClient http;

      String serverPath = serverName + "teplota=" + temp.temperature + "&humV=" + humidity.relative_humidity; //GUID pro teplotu "teplota", pro vlhkost "humV"
      
      // zacatek http spojeni
      http.begin(serverPath.c_str());
      
      // http get request
      int httpResponseCode = http.GET();
      
      if (httpResponseCode>0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        String payload = http.getString();
        Serial.println(payload);
      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }
      // Free resources
      http.end();
    }
    else {
      Serial.println("Wi-Fi odpojeno");
    }

  delay(60000);
}
