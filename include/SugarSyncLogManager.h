/**
 * @file LogTracker.h
 * @author cptea
 * @brief
 * @version 1.0.0
 * @date 2021-08-30
 *
 * @copyright Copyright (c) 2021 cptea
 *
 */

#ifndef __SUGARSYNCLOG_SUGARSYNCLOGMANAGER_H__
#define __SUGARSYNCLOG_SUGARSYNCLOGMANAGER_H__

#include <cstdio>
#include <memory>
#include <string>

namespace sugar {

template <typename... Args>
static std::string format(const std::string& fmt, Args... args);

namespace sync {
namespace log {

enum class LogTarget {
  None = 0x00,
  File = 0x01,
  Console = 0x02,
  Debugger = 0x04
};

enum class LogLevel {
  None,
  Error,
  Warning,
  Debug,
  Info,
};

class Logger {
 public:
  virtual void write(const char* target, const char* message) = 0;

  virtual std::string format(const char* target, const char* message,
                             const char* file, const char* func, int line,
                             int tid, int pid);

  virtual ~Logger() {};

  // virtual void clear() = 0;
};

class FileLogger : public Logger {
 public:
  void write(const char* target, const char* message) override;
};

class LogManager {
 public:
  LogManager& getInstance();

 private:
  LogManager() = default;
  ~LogManager() = default;
  LogManager(const LogManager&) = delete;
  LogManager& operator=(const LogManager&) = delete;
};

}  // namespace log
}  // namespace sync
}  // namespace sugar

template <typename... Args>
std::string sugar::format(const std::string& fmt, Args... args) {
  auto size = std::snprintf(nullptr, 0, fmt.c_str(), args...) + 1;
  std::unique_ptr<char[]> buffer(new char[size]);
  std::snprintf(buffer.get(), size, fmt.c_str(), args...);
  return std::string(buffer.get(), buffer.get() + size - 1);
}

// sugar::sync::log::Logger::~Logger(){}

#endif
