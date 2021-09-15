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
#include <ctime>
#include <exception>
#include <iostream>
#include <memory>
#include <string>

#include "LogTarget.h"

namespace sugar {
template <typename... Args>
std::string formatString(const char* fmt, Args... args) {
  try {
    auto size = std::snprintf(nullptr, 0, fmt, args...) + 1;
    std::unique_ptr<char[]> buffer(new char[size]);
    std::snprintf(buffer.get(), size, fmt, args...);
    return std::string(buffer.get(), buffer.get() + size - 1);
  } catch (std::exception ex) {
    std::cout << ex.what() << std::endl;
  }
}

std::string formatDateTime(const tm& dateTime,
                           const char* fmt = "%Y/%m/%d %H:%M:%S");

std::string formatTarget(const int& target);

}  // namespace sugar

#endif
