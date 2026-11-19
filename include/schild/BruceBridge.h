#pragma once

#include <stdint.h>

namespace schild {

// Interfaccia neutra tra SCHILD e la UI di Bruce.
// L'adapter della specifica versione Bruce dovra' collegare queste callback
// al display, al touch/tasti e al ciclo di vita della schermata.
struct BruceUi {
  void* context = nullptr;
  void (*clear)(void* context) = nullptr;
  void (*printLine)(void* context, uint8_t row, const char* text) = nullptr;
  bool (*backPressed)(void* context) = nullptr;
};

class BruceBridge {
 public:
  void begin(const BruceUi& ui);
  void loop();
  void end();

  bool isRunning() const { return running_; }

 private:
  void drawStatus();

  BruceUi ui_{};
  bool running_ = false;
};

}  // namespace schild
