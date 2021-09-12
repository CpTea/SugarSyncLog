#include "SugarSyncLogManager.h"

#include <chrono>
#include <iomanip>
#include <sstream>

using namespace sugar::sync::log;

std::string Logger::format(const char* target, const char* message,
                           const char* file, const char* func, int line,
                           int tid, int pid) {
  const char* fmt = "[%s] [%5s] [TID:%04x] [PID:%04x] %s.%s %08x: %s\n";
  auto t =
      std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

  std::stringstream strstream;
  strstream << std::put_time(std::localtime(&t), "%Y/%m/%d %H:%M:%S");
  return sugar::format(fmt, strstream.str().c_str(), target, tid, pid, line, file, func, message);
}
