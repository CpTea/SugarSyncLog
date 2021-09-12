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

#ifndef __SUGARSYNCLOG_SUGAR_SYNC_LOG_H__
#define __SUGARSYNCLOG_SUGAR_SYNC_LOG_H__

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

#include <SugarSyncLogManager.h>

class SUGAR_INT sugar::sync::log::FileLogger;
class SUGAR_API sugar::sync::log::Logger;

#endif