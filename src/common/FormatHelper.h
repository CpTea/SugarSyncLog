/**
 * @file LogTarget.h
 * @author cptea
 * @brief
 * @version 1.0.0
 * @date 2021-09-14
 */
#pragma once
#ifndef __SUGAR_FORMATHELPER_H__
#define __SUGAR_FORMATHELPER_H__
// #include <ctime>
// #include <exception>
// #include <iostream>
// #include <memory>
#include <string>

#include "LogTarget.h"

namespace sugar {
// std::string formatDateTime(const tm& dateTime,
//                            const char* fmt = "%Y/%m/%d %H:%M:%S");

std::string formatTarget(const int& target);

}  // namespace sugar

#endif
