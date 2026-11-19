#pragma once
#include <stdint.h>

namespace schild {
struct GpsFix {
  bool valid = false;
  bool hasDate = false;
  bool hasAltitude = false;
  bool hasSpeed = false;
  bool hasCourse = false;
  double latitudeDeg = 0.0;
  double longitudeDeg = 0.0;
  double altitudeMeters = 0.0;
  double speedKnots = 0.0;
  double courseDeg = 0.0;
  uint8_t satellites = 0;
  uint8_t day = 0;
  uint8_t month = 0;
  uint16_t year = 0;
  uint32_t utcMillisOfDay = 0;
};
}  // namespace schild
