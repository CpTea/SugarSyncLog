/**
 * @file LogTarget.h
 * @author cptea
 * @brief
 * @version 1.0.0
 * @date 2021-09-14
 */

#include "FileLogger.h"

#include <filesystem>
#include <fstream>

#include "common/FormatHelper.h"

using namespace sugar::sync::log;

FileLogger::FileLogger(int level) {
  setLogLevel(level);
  // setStorageDirectory(".");
}

void FileLogger::write(int target, const char* message) {
  if (target < getLogLevel()) return;
  auto t =
      std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  auto filename = getSotrageDirectory() +
                  sugar::formatDateTime(*std::localtime(&t), "%F") + ".log";
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
  _storageDirectory += "/log";
  std::filesystem::create_directories(_storageDirectory);
}
