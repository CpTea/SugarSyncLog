/**
 * @file LogTracker.cpp
 * @author cptea
 * @brief
 * @version 1.0.0
 * @date 2021-08-30
 *
 * @copyright Copyright (c) 2021 cptea
 *
 */

#include "LogTracker.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <chrono>

#ifdef _WIN32
#define PATH_SEPARATOR "\\"
#else
#define PATH_SEPARATOR "/"
#endif


sugar::synclog::LogTracker::LogTracker()
    : _trackerLevel(sugar::synclog::LogTrackerLevel::All) {}

std::string format(const sugar::synclog::MessageType& type, std::string message,
                   std::string callerName, std::string callerPath,
                   int callerLine) {
  std::stringstream msg;
  auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  msg << "[" << std::put_time(std::localtime(&t), "%Y/%m/%d %H%M%S") << "] " ;


  return 0;
}