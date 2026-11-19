#include "SchildMenu.h"
#include "core/display.h"
#include "core/mykeyboard.h"

static void schildShowInfo(const String& title, const String& line1,
                           const String& line2, const String& line3) {
    tft.fillScreen(BGCOLOR);
    drawMainBorderWithTitle(title);
    setTftDisplay(12, 48, FGCOLOR, FM, BGCOLOR);
    tft.println(line1);
    tft.println(line2);
    tft.println(line3);
    setTftDisplay(12, HEIGHT - 25, FGCOLOR, FP, BGCOLOR);
    tft.print("BACK per tornare");
    while (!checkEscPress()) {
        delay(20);
    }
    returnToMenu = true;
}

void SchildMenu::optionsMenu() {
    options = {
        {"Stato progetto", []() {
            schildShowInfo("SCHILD / STATO",
                "Interfaccia Bruce 1.6",
                "Moduli hardware in sviluppo",
                "Nessuna trasmissione attiva");
        }},
        {"Analisi RF", []() {
            schildShowInfo("SCHILD / RF",
                "Modulo passivo previsto",
                "Richiede driver compatibile",
                "Nessun TX / jammer");
        }},
        {"GPS", []() {
            schildShowInfo("SCHILD / GPS",
                "GPS opzionale non collegato",
                "Parser NMEA nel core SCHILD",
                "UART da configurare");
        }},
        {"Test schermatura", []() {
            schildShowInfo("SCHILD / SHIELD",
                "Test comparativo previsto",
                "Servono sensori supportati",
                "Misure da validare");
        }},
        {"Torna al menu", []() {
            backToMenu();
        }}
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
