# ESP32 LPkit

Do you have a project in your head where you need to combain a low power consumption, high power and Wi-Fi and Bluetooth connection? Discover our evaluation board based on ESP32 module called ESP32 LPkit.
During the development of this board, we also thought about other features which you may use - for example built-in Li-ion charger. 

## Pinout

![ESP32 LPkit pipnout](https://github.com/LaskaKit/ESP32-LPKit/blob/main/img/ESP32LPkit1_1.jpg)

As you can see on the picture above, ESP32 LPkit board contains microUSB connector for (only) charging of Li-ion battery, connector for Li-ion battery, RESET button and FLASH button, and GPIO headers on both sides of board.

On the bottom side, there is programming connector.

## Charging IC for Li-ion battery

Li-ion battery is charged by microUSB connector, the used charger IC is TP4054. 
The charging current is defined by resistor R11. 
How to change the charging current you find out on the formula below. 

If you don't change the resistor R11, the default value is 1k65 so the maximum current charging current is 400 mA. 

![What should be the value of resistor for my charging current](https://github.com/LaskaKit/ESP32-LPKit/blob/main/img/ESP32LPkit3.jpg)

## Power consumption

The power consumption of ESP32 LPkit is only 6.5 uA (powered from Li-ion battery, 4.2V) during the deep-sleep. 6.5uA means the whole board - ESP32, LDO etc. without CH340 programmer.

![ESP32 LPkit and CH340 programmer](https://github.com/LaskaKit/ESP32-LPKit/blob/main/img/ESP32LPkit2.jpg)

## Programming

The uploading of your code is really easy thanks to our “CH340 programmer”, you just plug in the connector from CH340 programmer to ESP32 LPkit. Then you connect microUSB or USB-C connector to programmer and in Arduino IDE, you click on "Upload". Programmer automatically start the ESP32 to bootloader mode and upload the code. 
Of course, the CH340 programmer is not needed for uploading of your code. You may use every USB-UART convertor with RX, TX, DTR and RTS pins. 

In case you don't have an USB-UART programmer with DTR and RTS pins, you may use RESET and FLASH buttons to reset the ESP32 and switch to bootloader mode. 

Press FLASH button

Press RESET and still hold FLASH button

Release RESET button

And then also release FLASH button

Now ESP32 is in bootloader mode, you just click on "Upload" in you Arduino IDE

The example code you can find here (https://github.com/LaskaKit/Testcode_examples/tree/main/Boards/ESP32%20LPkit)
