# ESP32 LPkit

Do you have a project in your head where you need to combain a low power consumption, high power and Wi-Fi and Bluetooth connection? Discover our evaluation board based on ESP32 module called [ESP32 LPkit](https://www.laskakit.cz/laskakit-esp32-lpkit-pcb-antenna/).
During the development of this board, we also thought about other features which you may use - for example built-in Li-ion charger. 

## Pinout

![ESP32 LPkit pinout](https://github.com/LaskaKit/ESP32-LPKit/blob/main/img/ESP32-LPkit_pinout.JPG)

As you can see on the picture above, [ESP32 LPkit](https://www.laskakit.cz/laskakit-esp32-lpkit-pcb-antenna/) board contains popular and versatile USB-C connector for (only) charging of Li-ion battery, connector for Li-ion battery, RESET button and FLASH button, and GPIO headers on both sides of board and our connector called μŠup.

![ESP32 LPkit pinout](https://github.com/LaskaKit/ESP32-LPKit/blob/main/img/esp32-lpkit-back_popis.jpg)

On the bottom side, there is programming connector. The connector is pin-to-pin compatible with our programmer called [LaskaKit CH340 programmer](https://www.laskakit.cz/laskakit-ch340-programmer-usb-c--microusb--uart/). 

We are 100% sure that you will appreciate our μŠup connector. It is small, durable and safe connector for connection to other evaluation board and sensor boards. The μŠup connector is pin-to-pin compatible with Adafruit Stemma a Sparkfun Qwiik. We offer a lot of sensors and board and we are designing a new board and sensors. 

## Charging IC for Li-ion battery

Li-ion battery is charged by USB-C connector, the used charger IC is TP4054. 
The charging current is defined by resistor R11. 
How to change the charging current you find out on the formula below. 

If you don't change the resistor R11, the default value is 1k65 so the maximum current charging current is 400 mA. 

## Power consumption

![What should be the value of resistor for my charging current](https://github.com/LaskaKit/ESP32-LPKit/blob/main/img/ESP32LPkit3.jpg)

The power consumption of ESP32 LPkit is only 6.5 uA (powered from Li-ion battery, 4.2V) during the deep-sleep. 6.5uA means the whole board - ESP32, LDO etc. without CH340 programmer.

## Programming

![ESP32 LPkit and CH340 programmer](https://github.com/LaskaKit/ESP32-LPKit/blob/main/img/ESP32LPkit2.jpg)

The uploading of your code is really easy thanks to our “[LaskaKit CH340 programmer](https://www.laskakit.cz/laskakit-ch340-programmer-usb-c--microusb--uart/)”, you just plug in the connector from CH340 programmer to ESP32 LPkit. Then you connect microUSB or USB-C connector to programmer and in Arduino IDE, you click on "Upload". Programmer automatically start the ESP32 to bootloader mode and upload the code. 
Of course, the [LaskaKit CH340 programmer](https://www.laskakit.cz/laskakit-ch340-programmer-usb-c--microusb--uart/) is not needed for uploading of your code. You may use every USB-UART convertor with RX, TX, DTR and RTS pins. Don't forget to switch to 3.3V!

In case you don't have an USB-UART programmer with DTR and RTS pins, you may use RESET and FLASH buttons to reset the ESP32 and switch to bootloader mode. 

Press FLASH button

Press RESET and still hold FLASH button

Release RESET button

And then also release FLASH button

Now ESP32 is in bootloader mode, you just click on "Upload" in you Arduino IDE

The example code you can find here (https://github.com/LaskaKit/ESP32-LPKit/tree/main/SW)

The ultra low-power eval board LaskaKit ESP32-LPkit is on https://www.laskakit.cz/laskakit-esp32-lpkit-pcb-antenna/

The programmer is available on https://www.laskakit.cz/laskakit-ch340-programmer-usb-c--microusb--uart/
