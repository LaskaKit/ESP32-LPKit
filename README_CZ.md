# ESP32 LPkit

Stojíš před projektem, kde řešíš nízkou spotřebu, potřebu vysokého výkonu čipu a Wi-Fi nebo Bluetooth připojení? Pak by se ti mohl hodit náš vývojový kit nazvaný ![ESP32 LPkit](https://www.laskakit.cz/laskakit-esp32-lpkit-pcb-antenna/).
Během vývoje desky ![ESP32 LPkit](https://www.laskakit.cz/laskakit-esp32-lpkit-pcb-antenna/) jsme mysleli i na další vychytávky, který bys mohl potřebovat - třeba nabíjení připojeného Lipol akumulátoru. 

Rozmístění

![ESP32 LPkit rozmístění](https://github.com/LaskaKit/ESP32-LPKit/blob/main/img/esp32-lpkit-front_popis.jpg )

Jak můžeš vidět na obrázku výše, vývojový kit ![ESP32 LPkit](https://www.laskakit.cz/laskakit-esp32-lpkit-pcb-antenna/) obsahuje USB-C konektor pouze pro nabíjení akumulátoru, konektor pro Lipol akumulátor, tlačítko RESET a FLASH, a GPIO hřebínky po obou stranách desky. 

Co jsme si 100% jistí je, že se ti zalíbí náš konektor, který jsme nazvali μŠup. Je to malý, zároveň odolný a nemůže se ti stát, že bys čidlo přepóloval. Je prostě bezpečný. S tímto konektorem můžeš vývojovou desku připojit k další spoustě čidel a desek. Některé už máme skladem, na jiných pracujeme. Konektor je pinově kompatibilní s Adafruit Stemma a Sparkfun Qwiik.

Z druhé desky je pak programovací konektor.

![ESP32 LPkit rozmístění](https://github.com/LaskaKit/ESP32-LPKit/blob/main/img/esp32-lpkit-back_popis.jpg )

## Nabíjecí obvod akumulátoru

Li-ion akumulátor je nabíjen skrze moderní a univerzální USB-C konektor, nabíjení je řízeno čipem TP4054. 
Nabíjecí proud je dán rezistorem R11. 
Výpočet nalezneš níže, kde Rprog je rezistor R11.

Pokud rezistor R11 nezměníte, jeho hodnota je 1k65 a maximální nabíjecí proud je 400 mA. 

![Vzorec pro výpočet nabíjecího proudu](https://github.com/LaskaKit/ESP32-LPKit/blob/main/img/ESP32LPkit3.jpg)

## Spotřeba

Spotřeba ESP32 LP kit během režimu spánku je pouhých 6,5 uA (při 4,2V). To znamená, že celá deska, napájena pouze z Li-ion akumulátoru bez připojeného ![LaskaKit CH340 programmer](https://www.laskakit.cz/laskakit-ch340-programmer-usb-c--microusb--uart/) odebírá pouze 6,5uA.

## Programování

![ESP340 LPkit and CH340 programmer](https://github.com/LaskaKit/ESP32-LPKit/blob/main/img/ESP32LPkit2.jpg)

Programování je díky našemu programátoru “![LaskaKitCH340 programmer](https://www.laskakit.cz/laskakit-ch340-programmer-usb-c--microusb--uart/)” velmi jednoduché, programátor zasuneš do konektoru, připojíš microUSB konektor nebo USB-C konektor do programátoru, v Arduino IDE vybereš port, kam je programátor připojený a tvůj kód nahraješ kliknutím na “Nahrát”. Na programátoru přepni na 3.3V!

Pokud nemáš náš programátor nebo jiný USB-UART převodník bez DTR a RTS pinu, pak je třeba před nahráním vstoupit do bootloader módu, což provedeš kombinací tlačítek RESET a FLASH

Stiskni FLASH

Stiskni RESET a stále drž FLASH

Uvolni RESET

Nakonec uvolni i tlačítko FLASH

Poté stačí kliknout na “Nahrát” ve tvém Arduino IDE.

Vzorový kód nalezneš na https://github.com/LaskaKit/Testcode_examples/tree/main/Boards/ESP32%20LPkit

ESP32-LPKit si můžeš zakoupit na https://www.laskakit.cz/laskakit-esp32-lpkit-pcb-antenna/
