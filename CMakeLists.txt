cmake_minimum_required(VERSION 3.8)
project(ConnectFour)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp game.cpp game.h players.cpp players.h)
add_executable(ConnectFour ${SOURCE_FILES})