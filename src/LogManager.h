/**
 * @file LogTarget.h
 * @author cptea
 * @brief
 * @version 1.0.0
 * @date 2021-08-30
 */

#ifndef __SUGAR_SYNC_LOG_LOGMANAGER_H__
#define __SUGAR_SYNC_LOG_LOGMANAGER_H__

#include <string>
#include <vector>

#include "common/LogLevel.h"
#include "logger/Logger.h"

namespace sugar {

namespace sync {
namespace log {

class LogManager {
 public:
  // LogManager& getInstance();
  static void enable(int loggerType, int logLevel);
  static void disable();

 private:
  LogManager() = default;
  ~LogManager();
  LogManager(const LogManager&) = delete;
  LogManager& operator=(const LogManager&) = delete;

  static void write(int target, const std::string& message,
                    const std::string& file, const std::string& func,
                    const int& line, const int& pid, const int& tid);

  static std::vector<Logger*> _loggers;
};

}  // namespace log
}  // namespace sync
}  // namespace sugar

// sugar::sync::log::Logger::~Logger(){}

#endif
