# SCHILD per Bruce 1.6

Questa integrazione aggiunge **SCHILD come voce del menu principale** di Bruce 1.6.

## Installazione

1. Scarica il sorgente Bruce dal tag/branch 1.6 e apri la sua cartella principale.
2. Fai una copia di sicurezza del sorgente.
3. Scarica questo file dal repository SCHILD: `integrations/bruce-1.6/menu.patch`.
4. Copia `menu.patch` nella cartella principale del sorgente Bruce.
5. Apri un terminale in quella cartella ed esegui:

```sh
git apply --check menu.patch
git apply menu.patch
```

6. Se il primo comando non segnala errori, il secondo applica la modifica.
7. Compila Bruce selezionando la configurazione esatta della tua CYD.

La patch crea `src/core/menu_items/SchildMenu.h` e `SchildMenu.cpp`, registra la classe in `main_menu.h` e aggiunge la voce all'elenco in `main_menu.cpp`.

## Funzioni presenti in questa prima integrazione

- Voce **SCHILD** nel menu principale.
- Stato del modulo.
- Pagine informative per analisi RF passiva, GPS e test schermatura.

## Importante: cosa non è ancora collegato

Questa versione collega **il menu**, non ancora i driver hardware. Le pagine RF e schermatura sono informative e non leggono ancora l'NRF HAT o un sensore EMF. Il GPS non è ancora collegato alla UART. Non vengono eseguite trasmissioni radio.

Non sono stati verificati i pin del tuo HAT CYD e non è stato eseguito un build su hardware: non collegare pin a tentativi. Il firmware `.bin` verrà prodotto solo dopo aver integrato i driver corretti e compilato per la precisa variante della scheda.
