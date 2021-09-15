/**
 * @file SugarSyncLog.h
 * @author cptea
 * @brief
 * @version 1.0.0
 * @date 2021-08-30
 *
 * @copyright Copyright (c) 2021 cptea
 *
 */

#ifndef __SUGAR_SYNC_LOG_SUGARSYNCLOG_H__
#define __SUGAR_SYNC_LOG_SUGARSYNCLOG_H__

// #include <LogManager.h>
// #include <common/LogTarget.h>

// #ifdef _MSC_VER
// #ifdef SUGAR_EXPORT
// #define SUGAR_API __declspec(dllexport)
// #else
// #define SUGAR_API __declspec(dllimport)
// #endif
// #define SUGAR_INT
// #else
// #define SUGAR_API __attribute((visibility("default")))
// #define SUGAR_INT __attribute((visibility("hidden")))
// #endif

#define SUGAR_API

#define LOGGER_FILE 0x01
#define LOGGER_CONSOLE 0x02

struct SugarSyncLog {
  virtual void enable(int loggerType, int level) = 0;
  virtual void disable() = 0;
  virtual void writeDebug(const char* message) = 0;
  virtual ~SugarSyncLog() {}
};

// #ifdef __cplusplus
// extern "C" {
// #endif

SUGAR_API SugarSyncLog* getSugarSyncLog();
SUGAR_API void releaseSugarSyncLog(SugarSyncLog*);

// #ifdef __cplusplus
// }
// #endif

// namespace sugar {
// namespace sync {
// namespace log {

// }  // namespace log
// }  // namespace sync
// }  // namespace sugar

#endif