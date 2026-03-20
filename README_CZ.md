# ESP32 LPkit

Stojíš před projektem, kde řešíš nízkou spotřebu, potřebu vysokého výkonu čipu a Wi-Fi nebo Bluetooth připojení? Pak by se ti mohl hodit náš vývojový kit nazvaný [ESP32 LPkit](https://www.laskakit.cz/laskakit-esp32-lpkit-pcb-antenna/).
Během vývoje desky [ESP32 LPkit](https://www.laskakit.cz/laskakit-esp32-lpkit-pcb-antenna/) jsme mysleli i na další vychytávky, který bys mohl potřebovat - třeba nabíjení připojeného Lipol akumulátoru. 

## Pinout

![ESP32 LPkit Pinout](https://github.com/LaskaKit/ESP32-LPKit/blob/main/img/ESP32-LPkit_pinout.png)

Jak můžeš vidět na obrázku výše, vývojový kit [ESP32 LPkit](https://www.laskakit.cz/laskakit-esp32-lpkit-pcb-antenna/) obsahuje USB-C konektor pro nabíjení akumulátoru a programovaní, konektor pro Lipol akumulátor, tlačítko RESET a FLASH, a GPIO hřebínky po obou stranách desky. Mimo již zmíněné konektory ze můžeš také najít náš μŠup. Je to malý, a zároveň odolný konektor, díky kterému navíc už nikdy svoje čidlo nepřepóluješ! 

Konektor μŠup je pinově kompatibilní s Adafruit Stemma a Sparkfun Qwiik.

## Nabíjecí obvod akumulátoru

Li-ion akumulátor je nabíjen skrze moderní a univerzální USB-C konektor, nabíjení je řízeno čipem TP4054. 
Nabíjecí proud je dán ploškami na zadní straně desky. Propájením/přeříznutím plošky si můžeš vybrat proud 400mA (výchozí) nebo 260mA. 

## Spotřeba

Spotřeba ESP32 LP kit během režimu spánku je pouhých 6,5 uA (při 4,2V). To znamená, že celá deska, napájena pouze z Li-ion akumulátoru bez připojených periferií odebírá pouze 6,5uA.

## Programování

Deska má zabudovaný programátor CH9102, který nevyžaduje stahování žádných řadičů ani mačkání FLASH tlačítka - v Arduino IDE vybereš port, nahraješ kód a máš hotovo.

Je možné, že před prvním naprogramováním se programátor nespustí správně - pak je třeba před nahráním vstoupit do bootloader módu, což provedeš kombinací tlačítek RESET a FLASH

Stiskni FLASH

Stiskni RESET a stále drž FLASH

Uvolni RESET

Nakonec uvolni i tlačítko FLASH

Poté stačí kliknout na “Nahrát” ve tvém Arduino IDE.

Vzorový kód nalezneš na https://github.com/LaskaKit/ESP32-LPKit/tree/main/SW

##
## **ESP32-LPKit si můžeš zakoupit [zde](https://www.laskakit.cz/laskakit-esp32-lpkit-pcb-antenna/)**
