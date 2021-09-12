/**
 * @file libapi.h
 * @author cptea
 * @brief Related macro definitions required when exporting the library.
 * @version 1.0.0
 * @date 2021-08-29
 *
 * @copyright Copyright (c) 2021 CpTea
 *
 */

#ifndef __SUGARSYYNCLOG_API_H__
#define __SUGARSYYNCLOG_API_H__

#ifdef _MSC_VER
#ifdef _EXPORT
#define SUGAR_API __declspec(dllexport)
#else
#define SUGAR_API __declspec(dllimport)
#endif
#define SUGAR_INT

#else
#define SUGAR_API __attribute((visibility("default")))
#define SUGAR_INT __attribute((visibility("hidden")))
#endif

#endif
