/**
 * @file LogTarget.h
 * @author cptea
 * @brief
 * @version 1.0.0
 * @date 2021-09-14
 */

#include "LogManager.h"

#include <iostream>

#include "common/LogTarget.h"
#include "common/LoggerType.h"
#include "logger/FileLogger.h"

using namespace sugar::sync::log;

LogManager::~LogManager() { disable(); }

LogManager& LogManager::getInstance() {
  static LogManager instance;
  return instance;
}

void LogManager::enable(int loggerType, int logLevel) {
  disable();
  if (loggerType & LOGGER_FILE) {
    _loggers.push_back(new FileLogger(logLevel));
  }
  if (loggerType & LOGGER_CONSOLE) {
    // _loggers.push_back(new ConsoleLogger(loglevel));
  }
}

void LogManager::disable() {
  for (int i = 0; i < _loggers.size(); ++i) {
    if (_loggers[i]) delete _loggers[i];
  }
  _loggers.clear();
}

void LogManager::write(int target, const char* message, char* file,
                       const char* func, int line) {
  auto msg = Logger::formatMessage(target, message, file, func, line);
  for (auto logger : _loggers) {
    logger->write(target, msg.c_str());
  }
}

void LogManager::writeDebug(const char* message) {
  write(TARGET_DEBUG, message, 0, 0, 0);  // std::cout << message << std::endl;
}
