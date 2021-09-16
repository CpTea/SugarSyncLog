/**
 * @file LogTarget.h
 * @author cptea
 * @brief
 * @version 1.0.0
 * @date 2021-09-14
 */

// #define _CRT_SECURE_NO_WARNINGS


#include "FileLogger.h"

#include <filesystem>
#include <fstream>

#include "common/FormatHelper.h"

using namespace sugar::sync::log;

FileLogger::FileLogger(int level) {
  setLogLevel(level);
  setStorageDirectory(".");
  // setStorageDirectory(".");
}

void FileLogger::write(int target, const std::string& message) {
  if (target < getLogLevel()) return;
  auto filename = getSotrageDirectory() +
                  std::format("{:%F}", std::chrono::system_clock::now()) + ".log";
  std::ofstream outputFileSteam(filename, std::ios::app);
  outputFileSteam << message;
  outputFileSteam.close();
}

std::string FileLogger::getSotrageDirectory() const {
  return _storageDirectory;
}

void FileLogger::setStorageDirectory(const std::string& directory) {
  _storageDirectory = directory;
  if (_storageDirectory[_storageDirectory.length() - 1] == '\\' ||
      _storageDirectory[_storageDirectory.length() - 1] == '/') {
    _storageDirectory.pop_back();
  }
  _storageDirectory += "/log/";
  std::filesystem::create_directories(_storageDirectory);
}
