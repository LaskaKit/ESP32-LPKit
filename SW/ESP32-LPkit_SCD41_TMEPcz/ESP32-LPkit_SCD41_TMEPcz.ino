/*
* Vzorovy kod od laskakit.cz pro SCD41 s vyvojovym kitem ESP32-LPkit
* Kod posle pres seriovy port (UART) a zaroven na server TMEP.cz
* hodnoty teploty a vlhkosti z SCD41
* kazdou minutu
*
* SCD41 (https://www.laskakit.cz/laskakit-scd41-senzor-co2--teploty-a-vlhkosti-vzduchu/) je pripojen pres uSup konektor
* ESP32-LPkit (https://www.laskakit.cz/laskakit-esp32-lpkit-pcb-antenna/)
*
* Vytvoreno (c) laskakit.cz 2022
*
* Potrebne knihovny:
* https://github.com/sparkfun/SparkFun_SCD4x_Arduino_Library //SCD41
* https://github.com/madhephaestus/ESP32AnalogRead/ //Cteni z ADC s kalibracemi
*/

#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <ESP32AnalogRead.h>
#include "SparkFun_SCD4x_Arduino_Library.h"

/* TADY NASTAVIS - WI-FI A TMEP.CZ */
const char* ssid = "SSID";
const char* password = "PASSWORD";

// vypln tvou domenu cidla, kterou sis zaregistroval na tmep.cz
String serverName = "http://TVADOMENA.tmep.cz/index.php?";
// vypln tve GUID cidla
String GUID = "GUID"; 

/* KONEC NASTAVENI */

// SCD41
SCD4x SCD41;

// Cteni ADC 
ESP32AnalogRead adc;
float vBat = 0.0;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  delay(10);

  // inicializace
  //             begin, autokalibrace
  //               |      |
  if (SCD41.begin(false, true) == false)
  {
    Serial.println("SCD41 nenalezen.");
    Serial.println("Zkontroluj propojeni.");
    while(1)
      ;
  }
 
  // prepnuti do low power modu
  if (SCD41.startLowPowerPeriodicMeasurement() == true)  
  {
    Serial.println("Low power mod povolen.");
  }

  // nastaveni ADC
  adc.attach(34);

  // pripojeni k Wi-Fi
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
 
  // mereni napeti s ADC
  vBat = adc.readVoltage()*1.7693877551  // Voltage devider ratio on ADC pin 1MOhm + 1.3MOhm

  // odeslani hodnot pres UART
  Serial.print("Teplota: "); Serial.print(SCD41.getTemperature()); Serial.println(" degC");
  Serial.print("Vlhkost: "); Serial.print(SCD41.getHumidity()); Serial.println("% rH");
  Serial.print("CO2: "); Serial.print(SCD41.getCO2()); Serial.println(" ppm");
  Serial.print("Napeti: "); Serial.print(vBat); Serial.println(" V");

  // odeslani hodnot na TMEP.cz
  if(WiFi.status()== WL_CONNECTED)
  {
      HTTPClient http;
      
      //GUID, nasleduje hodnota teploty, pro vlhkost "humV", pro CO2 "CO2", pro napeti baterie "v"
      String serverPath = serverName + "" + GUID + "=" + SCD41.getTemperature() + "&humV=" + SCD41.getHumidity() + "&CO2=" + SCD41.getCO2() + "&v=" + vBat; 
      
      // zacatek http spojeni
      http.begin(serverPath.c_str());
      
      // http get request
      int httpResponseCode = http.GET();
      
      if (httpResponseCode>0) 
      {
        Serial.print("HTTP odpoved: ");
        Serial.println(httpResponseCode);
        String payload = http.getString();
        Serial.println(payload);
      }
      else 
      {
        Serial.print("Error kod: ");
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
