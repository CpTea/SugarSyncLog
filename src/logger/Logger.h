/**
 * @file SugarLogger.h
 * @author cptea
 * @brief Base class for logger
 * @version 1.0.0
 * @date 2021-09-13
 *
 * @copyright Copyright (c) 2021 cptea
 *
 */

#ifndef __SUGAR_SYNC_LOG_LOGGER_H__
#define __SUGAR_SYNC_LOG_LOGGER_H__
#include <string>

namespace sugar {
namespace sync {
namespace log {

class Logger {
 public:
  virtual void write(const char* target, const char* message) = 0;
  
  virtual ~Logger(){};
  virtual std::string format(const char* target, const char* message,
                             const char* file, const char* func, int line,
                             int tid, int pid);
  // virtual LogLevel getLogLevel() const;
  // virtual void setLogLevel(const LogLevel& level = LogLevel::Debug);

//  protected:
  // LogLevel _level;
};
}  // namespace log
}  // namespace sync
}  // namespace sugar
#endif