/**
 * @file FileLogger.h
 * @author cptea
 * @brief Save log to a local file
 * @version 1.0.0
 * @date 2021-09-13
 *
 * @copyright Copyright (c) 2021 cptea
 *
 */

#ifndef __SUGAR_SYNC_LOG_FILELOGGER_H__
#define __SUGAR_SYNC_LOG_FILELOGGER_H__

#include "Logger.h"

namespace sugar {
namespace sync {
namespace log {
class FileLogger : public Logger {
 public:
  void write(const char* target, const char* message) override;
  void setStorageDirectory(const std::string& directory);
  std::string getSotrageDirectory() const;

 private:
  std::string _storageDirectory;
  // std::string _storageFileName;
};
}  // namespace log
}  // namespace sync
}  // namespace sugar

#endif
