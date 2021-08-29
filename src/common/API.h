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
#define __API __declspec(dllexport)
#else
#define __API __declspec(dllimport)
#endif
#define __INT

#else
#define __API __attribute((visibility("default")))
#define __INT __attribute((visibility("hidden")))
#endif

#endif
