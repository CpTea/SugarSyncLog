/**
 * @file LogTarget.h
 * @author cptea
 * @brief 
 * @version 1.0.0
 * @date 2021-09-14 
 */

#include "Logger.h"

#include <chrono>

#include "common/FormatHelper.h"

using namespace sugar::sync::log;

Logger::~Logger() {}

std::string Logger::format(int target, const char* message,
                           const char* file, const char* func, int line,
                           int pid, int tid) {
  const char* fmt = "[%s] [%5s] [TID:%04x] [PID:%04x] %s.%s %08x: %s\n";
  auto t =
      std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  const char* datetime =
      sugar::formatDateTime(*std::localtime(&t), "%Y/%m/%d %H:%M:%S").c_str();
  const char* targetStr = sugar::formatTarget(target).c_str();
  return sugar::formatString(fmt, datetime, target, tid, pid, line, file, func,
                             message);
}

int Logger::getLogLevel() const { return _level; }

void Logger::setLogLevel(int level) { _level = level; }