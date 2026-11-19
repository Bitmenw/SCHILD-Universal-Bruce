#include "schild/GpsService.h"
namespace schild {
bool GpsService::ingestNmeaLine(const char* line) {
  return parser_.parseLine(line, fix_);
}
}  // namespace schild
