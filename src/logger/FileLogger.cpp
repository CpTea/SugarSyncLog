#include "FileLogger.h"

#include <iostream>

#include "common/StringHelper.h"

using namespace sugar::sync::log;

void FileLogger::write(const char* target, const char* message) {
  std::cout << format(target, message, 0, 0, 0, 0, 0);
}
