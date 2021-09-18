/**
 * @file LogTarget.h
 * @author cptea
 * @brief
 * @version 1.0.0
 * @date 2021-09-14
 *
 * @history
 * ![2021-09-18] Change the implementation of target conversion function to hash
 * table
 */

#include "Logger.h"
#include "Common/LogTarget.h"
#include "SugarSyncLog.h"

#include <chrono>
#include <filesystem>
#include <format>
#include <unordered_map>

using namespace sugar::sync::log;

const std::unordered_map<int, std::string> TargetCvtMap = {
    {TARGET_DEBUG, "DEBUG"}, {TARGET_INFO, "INFO"},   {TARGET_WARN, "WARN"},
    {TARGET_ERROR, "ERROR"}, {TARGET_FATAL, "FATAL"},
};

Logger::~Logger() {}

std::string Logger::formatMessage(int target,
                                  const std::string& message,
                                  const std::string& file,
                                  const std::string& func,
                                  int line) {
  auto fmt = "[{:%Y/%m/%d %T(%Z)}] [{:*>5s}] {}.{} {:08x}: {}\n";
  auto filename = std::filesystem::path(file).stem().string();
  return std::format(
      fmt, std::chrono::system_clock::now(), TargetCvtMap.find(target)->second,
      filename, func, line, message);
}

int Logger::getLogLevel() const {
  return _level;
}

void Logger::setLogLevel(int level) {
  _level = level;
}