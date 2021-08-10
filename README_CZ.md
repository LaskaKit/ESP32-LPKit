# ESP32 LPkit

Stojíte před projektem, kde řešíte nízkou spotřebu, potřebu vysokého výkonu čipu a Wi-Fi nebo Bluetooth připojení? Pak by se vám mohla hodit náš vývojový kit nazvaný ESP32 LPkit.
Během vývoje desky ESP32 LPkit jsme mysleli i na další vychytávky, které byste mohli potřebovat - třeba nabíjení připojeného Li-ion akumulátoru. 

Rozmístění

![ESP32 LPkit rozmístění](https://github.com/LaskaKit/ESP32-LPKit/blob/main/img/ESP32LPkit1.jpg)

Jak můžete vidět na obrázku výše, vývojový kit ESP32 LPkit obsahuje microUSB konektor pouze pro nabíjení akumulátoru, konektor pro Li-ion akumulátor, tlačítko RESET a FLASH, a GPIO hřebínky po obou stranách desky. 

Z druhé desky je pak programovací konektor.

## Nabíjecí obvod akumulátoru

Li-ion akumulátor je nabíjen skrze microUSB konektor, nabíjení je řízeno čipem TP4054. 
Nabíjecí proud je dán rezistorem R11. 
Výpočet naleznete níže, kde Rprog je rezistor R11.

Pokud rezistor R11 nezměníte, jeho hodnota je 1k65 a maximální nabíjecí proud je 400 mA. 

![Vzorec pro výpočet nabíjecího proudu](https://github.com/LaskaKit/ESP32-LPKit/blob/main/img/ESP32LPkit3.jpg)

## Spotřeba

Spotřeba ESP32 LP kit během režimu spánku je pouhých 6,5 uA (při 4,2V). To znamená, že celá deska, napájena pouze z Li-ion akumulátoru bez připojeného CH340 Programmer odebírá pouze 6,5uA.

![ESP340 LPkit and CH340 programmer](https://github.com/LaskaKit/ESP32-LPKit/blob/main/img/ESP32LPkit2.jpg)

## Programování

Programování je díky našemu programátoru “CH340 programmer” velmi jednoduché, programátor zasunete do konektoru, připojíte microUSB konektor nebo USB-C konektor do programátoru, v Arduino IDE vyberete port, kam je programátor připojený a váš kód nahrajete kliknutím na “Nahrát”.

Pokud nemáte náš programátor nebo jiný USB-UART převodník bez DTR a RTS pinu, pak je třeba před nahráním vstoupit do bootloader módu, což provedete kombinací tlačítek RESET a FLASH

Stiskněte FLASH

Stiskněte RESET a stále držte FLASH

Uvolněte RESET

Nakonec uvolněte i tlačítko FLASH

Poté stačí kliknout na “Nahrát” ve vašem Arduino IDE.

Vzorový kód naleznete na https://github.com/LaskaKit/Testcode_examples/tree/main/Boards/ESP32%20LPkit
