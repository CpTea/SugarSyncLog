/**
 * @file LogTarget.h
 * @author cptea
 * @brief
 * @version 1.0.0
 * @date 2021-09-14
 */

#include "LogManager.h"

#include <iostream>
#include <typeinfo>

#include "common/LogTarget.h"
#include "common/LoggerType.h"
#include "logger/FileLogger.h"

using namespace sugar::sync::log;

LogManager::~LogManager() {
  disable();
}

SugarSyncLog* LogManager::getInstance() {
  static LogManager instance;
  return &instance;
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
    if (_loggers[i])
      delete _loggers[i];
  }
  _loggers.clear();
}

void sugar::sync::log::LogManager::setStorageDirectory(const std::string& dir) {
    for (auto& logger : _loggers) {
        logger->setStorageDirectory(dir);
    }
}

void sugar::sync::log::LogManager::setLogLevel(int level) {
    for (auto& logger : _loggers) {
        logger->setLogLevel(level);
    }
}

void LogManager::write(int target,
                       const std::string& message,
                       const std::string& file,
                       const std::string& func,
                       int line) {
  auto msg = Logger::formatMessage(target, message, file, func, line);
  for (auto logger : _loggers) {
    logger->write(target, msg);
  }
}
