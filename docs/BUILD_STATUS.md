# Stato build e test

- [x] Struttura iniziale del repository.
- [x] Tipi GPS indipendenti dall'hardware.
- [x] Parser NMEA RMC/GGA iniziale con controllo checksum.
- [x] Prima integrazione del menu SCHILD per Bruce 1.6: classe menu e patch per registrarla nel menu principale.
- [ ] Applicazione della patch al checkout locale Bruce 1.6.
- [ ] Test automatici del parser.
- [ ] Configurazione build per la variante CYD esatta.
- [ ] Verifica pinout NRF HAT.
- [ ] Adapter UART GPS e scelta del modulo.
- [ ] Driver NRF24 in sola ricezione e analisi RF passiva.
- [ ] Funzioni reali di misura per il test schermatura.
- [ ] Compilazione e test su dispositivo.

La schermata menu usa le API presenti in Bruce 1.6 (`MenuItemInterface`, `loopOptions` e `displayInfo`). La patch si trova in `integrations/bruce-1.6/menu.patch`. Non è stata ancora applicata e compilata in un checkout Bruce locale.

Nessun firmware binario è incluso in questa fase. Il progetto non va considerato compilato finché una build riproducibile per il target specifico non sarà eseguita e verificata.
