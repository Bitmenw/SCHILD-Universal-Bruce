# Architettura SCHILD

## Principi
- Core indipendente da Bruce e dall'hardware specifico.
- Adapter separati per display, input, radio e GPS.
- Periferiche opzionali: l'assenza del GPS non deve impedire l'avvio.
- Nessun pin viene dato per certo finché il pinout CYD/HAT non è verificato.

## Livelli
1. Core: tipi di misura, timestamp, unità e risultati.
2. Hardware adapters: CYD display/touch, NRF24 in sola ricezione e GPS seriale.
3. Bruce adapter: voce di menu e ciclo di vita della schermata, da implementare dopo aver fissato la versione Bruce.
4. Logging: CSV/JSON locale, con coordinate facoltative.

## Moduli
RF/Wi-Fi in osservazione passiva; NRF24 in ricezione; EMF tramite sensori esterni calibrati; test schermatura comparativi; GPS tramite parser NMEA separato dall'UART fisica.

## Stato
Lo scaffold corrente contiene tipi GPS e parser NMEA di base. Non include ancora driver hardware, UI Bruce, driver NRF HAT, sensori EMF o sistema di build completo. Ogni modulo dovrà essere compilato e verificato sul target reale.
