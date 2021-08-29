cmake_minimum_required(VERSION 3.15)

project(
  SugarSyncLog
  VERSION 1.0.0
  LANGUAGES CXX
)

if (MSVC)
    set(CMAKE_C_FLAGS /source-charset:utf-8)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
add_subdirectory(src)
add_subdirectory(example)
