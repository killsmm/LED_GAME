cmake_minimum_required(VERSION 3.15)

project(LED_GAME)

set(CMAKE_CXX_STANDARD 17)

include_directories(./)

file(GLOB CPP_SOURCES "./*.cpp")

add_executable(LED_GAME ${CPP_SOURCES})

add_subdirectory(tests)
