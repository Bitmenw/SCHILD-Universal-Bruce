# SCHILD Universal Bruce

Moduli sperimentali per integrare strumenti di **analisi passiva e misurazione** in Bruce Firmware, inizialmente su ESP32 CYD 2.8" (240x320) con NRF HAT.

> **Stato: scaffold iniziale.** Questi file costituiscono una base software e documentale: non sono ancora collegati al menu Bruce, non sono stati compilati su hardware e non costituiscono un firmware pronto da installare.

## Hardware di riferimento
- ESP32 CYD 2.8", display 240x320.
- NRF HAT / shield collegato alla CYD; modello e pinout da verificare.
- GPS esterno previsto, ma opzionale: il codice GPS è indipendente dal modulo scelto.

## Moduli previsti
- RF Scanner: sola ricezione/analisi passiva, con hardware supportato.
- Wi-Fi Analyzer: scansione passiva delle reti visibili.
- NRF24 Analyzer: ricezione e analisi dei pacchetti, senza trasmissioni di disturbo.
- EMF Monitor: interfaccia per sensori esterni; misure quantitative solo con sensori calibrati adatti.
- Shielding Test: confronto prima/dopo in condizioni ripetibili.
- GPS: parser NMEA e servizio indipendente dal ricevitore fisico.
- RF Mapping: associazione delle misure a coordinate GPS quando disponibili.

## Struttura
- `include/schild/`: tipi e interfacce comuni.
- `src/gps/`: parser NMEA e servizio GPS.
- `docs/`: architettura, hardware e integrazione Bruce.

## GPS
Il parser accetta righe NMEA complete (ad esempio RMC e GGA). Il collegamento seriale, baud rate, pin RX/TX e alimentazione saranno configurati quando sarà scelto il modulo GPS. In assenza del ricevitore, il resto del progetto deve continuare a funzionare.

## Sicurezza e limiti
Il progetto è orientato a ricezione passiva, osservazione e misure. Non implementa jamming, interferenze intenzionali, deautenticazione Wi-Fi o blocco delle comunicazioni. NRF24L01+ non è uno strumento di misura EMF calibrato.

## Prossimi passi
1. Confermare modello esatto del CYD e pinout dello shield NRF.
2. Identificare la versione/commit di Bruce da usare come base.
3. Compilare i moduli per il target corretto.
4. Aggiungere il modulo al menu Bruce e verificare display, touch e periferiche.
5. Integrare e testare il GPS quando sarà acquistato.

Vedi [ARCHITECTURE](docs/ARCHITECTURE.md) e [HARDWARE](docs/HARDWARE.md).
