/**
 * @file LogTarget.h
 * @author cptea
 * @brief
 * @version 1.0.0
 * @date 2021-09-14
 */

// #define _CRT_SECURE_NO_WARNINGS

#include "Logger.h"

#include <chrono>
#include <format>

#include "common/FormatHelper.h"

using namespace sugar::sync::log;

Logger::~Logger() {}

std::string Logger::formatMessage(int target, const std::string& message,
                                  const std::string& file,
                                  const std::string& func, int line) {
  auto fmt = "[{:%Y/%m/%d %T (%z)}] [{:>5s}] {}.{} {:08x}: {}\n";
  //   auto t =
  //       std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  //   // =============================================
  //   // BUG: B2021091401
  //   // Breif: The following code cannot be written in one line, otherwise
  //   // formatString will report an error
  //   auto dt = sugar::formatDateTime(*std::localtime(&t), "%Y/%m/%d
  //   %H:%M:%S"); const char* datetime = dt.c_str(); auto targetTmp =
  //   sugar::formatTarget(target); auto targetStr = targetTmp.c_str();
  // =============================================
  return std::format(fmt, std::chrono::system_clock::now(),
                     sugar::formatTarget(target), file, func, line, message);
}

int Logger::getLogLevel() const { return _level; }

void Logger::setLogLevel(int level) { _level = level; }