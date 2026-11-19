#include "schild/BruceBridge.h"

namespace schild {

void BruceBridge::begin(const BruceUi& ui) {
  ui_ = ui;
  running_ = true;
  drawStatus();
}

void BruceBridge::loop() {
  if (!running_) return;

  // La gestione del tasto BACK viene delegata all'adapter Bruce.
  if (ui_.backPressed && ui_.backPressed(ui_.context)) {
    end();
  }
}

void BruceBridge::end() {
  running_ = false;
  if (ui_.clear) ui_.clear(ui_.context);
}

void BruceBridge::drawStatus() {
  if (ui_.clear) ui_.clear(ui_.context);
  if (!ui_.printLine) return;

  ui_.printLine(ui_.context, 0, "SCHILD");
  ui_.printLine(ui_.context, 1, "Modulo avviato");
  ui_.printLine(ui_.context, 2, "Bridge Bruce neutro");
  ui_.printLine(ui_.context, 3, "BACK: esci");
  ui_.printLine(ui_.context, 5, "RF passivo / GPS opzionale");
}

}  // namespace schild
