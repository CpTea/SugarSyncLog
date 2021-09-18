/**
 * @file LogTarget.h
 * @author cptea
 * @brief
 * @version 1.0.0
 * @date 2021-09-14
 */

#ifndef __SUGAR_SYNC_LOG_LOGGER_H__
#define __SUGAR_SYNC_LOG_LOGGER_H__
#include <ctime>
#include <string>

namespace sugar {
namespace sync {
namespace log {

class Logger {
 public:
  virtual void write(int target, const std::string& message) = 0;
  virtual void setStorageDirectory(const std::string& dir) = 0;

  virtual ~Logger();

  static std::string formatMessage(int target, const std::string& message,
                                   const std::string& file, const std::string& func,
                                   int line);
  int getLogLevel() const;
  void setLogLevel(int level);

 private:
  int _level;
};
}  // namespace log
}  // namespace sync
}  // namespace sugar
#endif
