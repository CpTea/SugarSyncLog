#include "FileLogger.h"

#include <iostream>

#include "common/StringHelper.h"

using namespace sugar::sync::log;

void FileLogger::write(const char* target, const char* message) {
  std::cout << format(target, message, 0, 0, 0, 0, 0);
}

std::string inline FileLogger::getSotrageDirectory() const{
  return _storageDirectory;
}

void FileLogger::setStorageDirectory(const std::string& directory) {
  _storageDirectory = directory;
}