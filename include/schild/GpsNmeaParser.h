#pragma once
#include "GpsTypes.h"

namespace schild {
// Parser minimale NMEA RMC/GGA. Passare una frase senza CR/LF.
class GpsNmeaParser {
 public:
  bool parseLine(const char* line, GpsFix& out) const;
 private:
  static bool checksumValid(const char* line);
};
}  // namespace schild
