/**
 * @file FileLogger.h
 * @author cptea
 * @brief
 * @version 1.0.0
 * @date 2021-09-14
 */

#ifndef __SUGAR_SYNC_LOG_FILELOGGER_H__
#define __SUGAR_SYNC_LOG_FILELOGGER_H__

#include <string>
#include "Logger.h"

namespace sugar {
namespace log {
namespace sync {
class FileLogger : public Logger {
 public:
  FileLogger(int level);
  void write(int target, const std::string& message) override;
  void setStorageDirectory(const std::string& directory) override;

  std::string getSotrageDirectory() const;

 private:
  std::string _storageDirectory;
};
}  // namespace sync
}  // namespace log
}  // namespace sugar

#endif
