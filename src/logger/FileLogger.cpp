/**
 * @file LogTarget.h
 * @author cptea
 * @brief 
 * @version 1.0.0
 * @date 2021-09-14 
 */

#include "FileLogger.h"

#include <filesystem>
// #include <iostream>
#include <fstream>

#include "common/FormatHelper.hpp"


using namespace sugar::sync::log;

FileLogger::FileLogger(int level) { setLogLevel(level); }

void FileLogger::write(int target, const char* message) {
  if (target)


  if (_storageDirectory[_storageDirectory.length() - 1] == '\\' ||
      _storageDirectory[_storageDirectory.length() - 1] == '/') {
    _storageDirectory.pop_back();
  }
  std::string logDir = _storageDirectory + "/log";
  std::filesystem::create_directories(logDir);
  auto t =
      std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  auto filename = formatDateTime(*std::localtime(&t), "%F") + ".log";
  std::ofstream outputFileSteam(filename, std::ios::app);
  outputFileSteam << format(target, message)
}

std::string inline FileLogger::getSotrageDirectory() const {
  return _storageDirectory;
}

void FileLogger::setStorageDirectory(const std::string& directory) {
  _storageDirectory = directory;
}