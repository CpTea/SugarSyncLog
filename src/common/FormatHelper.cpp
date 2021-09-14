#include "FormatHelper.h"

#include <iomanip>
#include <sstream>


std::string sugar::formatDateTime(const tm& dateTime, const char* fmt) {
  std::stringstream strstream;
  strstream << std::put_time(&dateTime, fmt);
  return strstream.str();
}

std::string sugar::formatTarget(const int& target) {
  switch (target) {
    case TARGET_DEBUG:
      return "DEBUG";
    case TARGET_INFO:
      return "INFO";
    case TARGET_WARN:
      return "WARN";
    case TARGET_ERROR:
      return "ERROR";
    case TARGET_FATAL:
      return "FATAL";
  }
  return 0;
}