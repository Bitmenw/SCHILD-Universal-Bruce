#pragma once
#include "GpsTypes.h"
#include "GpsNmeaParser.h"

namespace schild {
// L'UART viene fornita in futuro da un adapter specifico della scheda.
class GpsService {
 public:
  bool ingestNmeaLine(const char* line);
  bool hasFix() const { return fix_.valid; }
  const GpsFix& fix() const { return fix_; }
  void clear() { fix_ = GpsFix{}; }
 private:
  GpsNmeaParser parser_;
  GpsFix fix_{};
};
}  // namespace schild
