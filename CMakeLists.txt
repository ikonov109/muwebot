cmake_minimum_required(VERSION 3.25)

project(MuWeBot)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Эта строка подключает Geode SDK, чтобы CMake знал о функции setup_geode_mod
add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)

add_library(${PROJECT_NAME} SHARED
    src/main.cpp
    src/bot.cpp
)

setup_geode_mod(${PROJECT_NAME})
