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

#ifndef __SUGARSYNCLOG_LOGTRACKER_H__
#define __SUGARSYNCLOG_LOGTRACKER_H__

#include <string>

#include "LogTrackerLevel.h"
#include "MessageType.h"

namespace sugar {
namespace synclog {
class LogTracker {
 public:
  LogTracker();
  virtual ~LogTracker() {}

  virtual bool write(const MessageType& type, const char* msg) = 0;
  virtual std::string format(const MessageType& type, std::string message,
                             std::string callerName, std::string callerPath,
                             int callerLine);

 private:
  LogTrackerLevel _trackerLevel;
};
}  // namespace synclog
}  // namespace sugar

#endif