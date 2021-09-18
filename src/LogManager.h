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

#include "SugarSyncLog.h"
#include "common/LogLevel.h"
#include "logger/Logger.h"

namespace sugar {

namespace sync {
namespace log {

class LogManager : public SugarSyncLog {
 public:
  static SugarSyncLog* getInstance();
  void enable(int loggerType, int logLevel) override;
  void disable() override;
  void setStorageDirectory(const std::string& dir) override;
  void setLogLevel(int level) override;
  void write(int target,
             const std::string& message,
             const std::string& file,
             const std::string& func,
             int line) override;

 private:
  ~LogManager();
  LogManager() = default;
  LogManager(const LogManager&) = delete;
  LogManager& operator=(const LogManager&) = delete;

  std::vector<Logger*> _loggers;
};

}  // namespace log
}  // namespace sync
}  // namespace sugar

#endif
