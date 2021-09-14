/**
 * @file LogTarget.h
 * @author cptea
 * @brief 
 * @version 1.0.0
 * @date 2021-09-14 
 */

#include "LogManager.h"
#include "common/LoggerType.h"
#include "logger/FileLogger.h"

void sugar::sync::log::LogManager::enable(int loggerType, int logLevel) {
  disable();
  if(loggerType & LOGGER_FILE) {
    _loggers.push_back(new FileLogger(logLevel));
  }
}

void sugar::sync::log::LogManager::disable() {
  for(int i = 0; i < _loggers.size(); ++i){
    if(_loggers[i]) delete _loggers[i];
  }
  _loggers.clear();
}