#ifndef __SUGAR_StringHelper_H__
#define __SUGAR_StringHelper_H__
#include <string>

namespace sugar {
template <typename... Args>
std::string format(const std::string& fmt, Args... args) {
  auto size = std::snprintf(nullptr, 0, fmt.c_str(), args...) + 1;
  std::unique_ptr<char[]> buffer(new char[size]);
  std::snprintf(buffer.get(), size, fmt.c_str(), args...);
  return std::string(buffer.get(), buffer.get() + size - 1);
}
}  // namespace sugar

#endif
