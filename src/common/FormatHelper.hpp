/**
 * @file LogTarget.h
 * @author cptea
 * @brief 
 * @version 1.0.0
 * @date 2021-09-14 
 */

#ifndef __SUGAR_FORMATHELPER_H__
#define __SUGAR_FORMATHELPER_H__
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>

namespace sugar {
template <typename... Args>
std::string formatString(const std::string& fmt, Args... args) {
  auto size = std::snprintf(nullptr, 0, fmt.c_str(), args...) + 1;
  std::unique_ptr<char[]> buffer(new char[size]);
  std::snprintf(buffer.get(), size, fmt.c_str(), args...);
  return std::string(buffer.get(), buffer.get() + size - 1);
}

std::string formatDateTime(const tm& dateTime,
                           const char* fmt = "%Y/%m/%d %H:%M:%S") {
  std::stringstream strstream;
  strstream << std::put_time(&dateTime, fmt);
  return strstream.str();
}

std::string formatTarget(const int& target) {
  
}

}  // namespace sugar

#endif
