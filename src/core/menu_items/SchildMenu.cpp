#include "SchildMenu.h"
#include "core/display.h"

// SCHILD menu for Bruce 1.6.
// This first integration is deliberately passive: it exposes the module
// entry points without enabling radio transmission or assuming hardware pins.

void SchildMenu::optionsMenu() {
    options = {
        {"Stato SCHILD", []() {
            displayInfo("SCHILD: menu Bruce 1.6 attivo. Driver hardware in integrazione.", true);
        }},
        {"Analisi RF passiva", []() {
            displayInfo("RF passiva: richiede NRF HAT verificato e driver RX. Nessuna trasmissione.", true);
        }},
        {"GPS", []() {
            displayInfo("GPS opzionale: parser NMEA predisposto. UART e pin da configurare.", true);
        }},
        {"Test schermatura", []() {
            displayInfo("Test comparativo: richiede sensore adatto e calibrazione. NRF24 non misura EMF assoluto.", true);
        }},
    };

    delay(150);
    loopOptions(options, false, true, "SCHILD");
}

String SchildMenu::getName() {
    return _name;
}

void SchildMenu::draw() {
    tft.fillRect(iconX, iconY, 80, 80, BGCOLOR);
    tft.drawCircle(iconX + 40, iconY + 40, 30, FGCOLOR);
    tft.drawCircle(iconX + 40, iconY + 40, 22, FGCOLOR);
    tft.drawLine(iconX + 18, iconY + 40, iconX + 62, iconY + 40, FGCOLOR);
    tft.drawLine(iconX + 40, iconY + 18, iconX + 40, iconY + 62, FGCOLOR);
}
