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
  virtual void write(int target, const char* message) = 0;

  virtual ~Logger();
  virtual std::string format(int target, const char* message,
                             const char* file, const char* func, int line,
                             int pid, int tid);
  
  int getLogLevel() const;
  void setLogLevel(int level);

 private:
  int _level;
};
}  // namespace log
}  // namespace sync
}  // namespace sugar
#endif
