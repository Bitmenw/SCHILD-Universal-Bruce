# SCHILD per Bruce 1.6

Questa cartella contiene il primo adattatore menu specifico per il tag Bruce `1.6`.

## File

- `src/core/menu_items/SchildMenu.h`
- `src/core/menu_items/SchildMenu.cpp`
- `menu.patch`

## Installazione nel sorgente Bruce 1.6

1. Fai una copia della cartella del firmware Bruce.
2. Copia `SchildMenu.h` e `SchildMenu.cpp` in `src/core/menu_items/` del sorgente Bruce.
3. Applica `menu.patch` dalla cartella principale del sorgente Bruce, oppure modifica a mano i due file:
   - in `src/core/main_menu.h`, aggiungi l'include di `menu_items/SchildMenu.h`, poi il membro `SchildMenu schildMenu;`
   - in `src/core/main_menu.cpp`, aggiungi `&schildMenu,` nell'elenco `_menuItems`.
4. Copia i file del core SCHILD GPS e le relative dipendenze nella struttura prevista dal progetto.
5. Compila Bruce per la tua precisa variante CYD.

## Cosa compare

Dopo l'integrazione, nel carosello del menu principale appare la voce **SCHILD**. Per ora apre una schermata iniziale con voci informative per stato, RF, GPS e test schermatura.

## Limiti attuali

- Non è ancora un firmware pronto e non è stato compilato o provato su una CYD.
- Le schermate RF e schermatura sono segnaposto: non pilotano hardware.
- Il GPS è predisposto a livello parser NMEA, ma UART, pin e ricevitore non sono ancora configurati.
- Non collegare il modulo NRF HAT usando pin non verificati.
- Le funzioni radio previste sono esclusivamente di osservazione/ricezione passiva.
