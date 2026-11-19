# Hardware e configurazione

## Target iniziale
- ESP32 CYD 2.8", risoluzione dichiarata 240x320.
- NRF HAT / shield a due schede: modello e pinout non ancora identificati.
- GPS esterno da acquistare in seguito; non è richiesto per sviluppare il core GPS.

## Da verificare prima dei collegamenti
- Variante esatta CYD e revisione.
- Controller display e touch.
- Pin occupati da display, touch, SD e retroilluminazione.
- Modello NRF HAT, alimentazione e pin CE, CSN, SCK, MOSI, MISO, IRQ.
- Tensioni richieste da ogni modulo.

**Non collegare NRF o GPS usando pin scelti a caso.** Varianti CYD e shield possono avere cablaggi differenti.

## GPS futuro
Il core accetta frasi NMEA. Quando sarà scelto il modulo si definiranno alimentazione, UART e pin RX/TX liberi, baud rate e antenna/connettore compatibili.

## Nota sulle misure
Per misure EMF quantitative servono sensori adeguati e calibrati. Un NRF24L01+ o una scansione Wi-Fi non forniscono da soli una misura assoluta dell'intensità del campo elettromagnetico.
