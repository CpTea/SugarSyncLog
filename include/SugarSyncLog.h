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

#include <string>

#ifdef _MSC_VER
#ifdef SUGAR_EXPORT
#define SUGAR_API __declspec(dllexport)
#else
#define SUGAR_API __declspec(dllimport)
#endif
#define SUGAR_INT
#else
#define SUGAR_API __attribute((visibility("default")))
#define SUGAR_INT __attribute((visibility("hidden")))
#endif

#define LOGGER_FILE 0x01
#define LOGGER_CONSOLE 0x02

#define LEVEL_NONE 0x00
#define LEVEL_FATAL 0x01
#define LEVEL_ERROR 0x02
#define LEVEL_WARN 0x03
#define LEVEL_INFO 0x04
#define LEVEL_DEBUG 0x05

#define TARGET_FATAL 0x01
#define TARGET_ERROR 0x02
#define TARGET_WARN 0x03
#define TARGET_INFO 0x04
#define TARGET_DEBUG 0x05

struct SUGAR_INT SugarSyncLog {
  virtual void enable(int loggerType, int level) = 0;
  virtual void disable() = 0;
  virtual void setStorageDirectory(const std::string& dir) = 0;
  virtual void setLogLevel(int level) = 0;
  virtual void write(int target,
                     const std::string& message,
                     const std::string& file,
                     const std::string& func,
                     int line) = 0;
};

extern SUGAR_API SugarSyncLog* manager();

#define SugarLogEnable(loggerType, logLevel) (manager()->enable((loggerType), (logLevel)))
#define SugarLogSetStorageDirectory(dir) (manager()->setStorageDirectory(dir))
#define SugarLogSetLogLevel(level) (manager()->setLogLevel(level))
#define SugarLogDisable() (manager()->disable())

#define SugarLogDebug(message) (manager()->write(TARGET_DEBUG, (message), __FILE__, __FUNCTION__, __LINE__))
#define SugarLogInfo(message) (manager()->write(TARGET_INFO, (message), __FILE__, __FUNCTION__, __LINE__))
#define SugarLogWarn(message) (manager()->write(TARGET_WARN, (message), __FILE__, __FUNCTION__, __LINE__))
#define SugarLogError(message) (manager()->write(TARGET_ERROR, (message), __FILE__, __FUNCTION__, __LINE__))
#define SugarLogFatal(message) (manager()->write(TARGET_FATAL, (message), __FILE__, __FUNCTION__, __LINE__))

#endif