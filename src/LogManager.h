/**
 * @file LogTarget.h
 * @author cptea
 * @brief 
 * @version 1.0.0
 * @date 2021-08-30
 */

#ifndef __SUGAR_SYNC_LOG_LOGMANAGER_H__
#define __SUGAR_SYNC_LOG_LOGMANAGER_H__

#include <cstdio>
#include <memory>
#include <string>

namespace sugar {

namespace sync {
namespace log {

class LogManager {
 public:
  // LogManager& getInstance();

 private:
  LogManager() = default;
  ~LogManager() = default;
  LogManager(const LogManager&) = delete;
  LogManager& operator=(const LogManager&) = delete;
};


}  // namespace log
}  // namespace sync
}  // namespace sugar



// sugar::sync::log::Logger::~Logger(){}

#endif
