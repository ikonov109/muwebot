cmake_minimum_required(VERSION 3.25)

project(MuWeBot)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME} SHARED
    src/main.cpp
    src/bot.cpp
)

setup_geode_mod(${PROJECT_NAME})
