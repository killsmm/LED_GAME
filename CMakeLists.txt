cmake_minimum_required(VERSION 3.15)

project(LED_GAME)

set(CMAKE_CXX_STANDARD 17)

add_executable(LED_GAME main.cpp Game.cpp HALFactory.cpp HAL.cpp Terminal.cpp)

target_link_libraries(LED_GAME pthread)