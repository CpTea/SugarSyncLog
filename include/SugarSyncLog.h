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

#include <iostream>

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

namespace sugar {
namespace sync {
namespace log {
enum class SUGAR_API LogTarget { None = 0x00, File = 0x01, Console = 0x02 };

enum class SUGAR_API LogLevel {
  None,
  Error,
  Warning,
  Debug,
  Info,
};

class SUGAR_API HelloWorldHelper {
 public:
  void Print() const { std::cout << "Hello World!" << std::endl; }
};

}  // namespace log
}  // namespace sync
}  // namespace sugar

#endif