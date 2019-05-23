cmake_minimum_required(VERSION 3.9)
project(APD)

set(CMAKE_CXX_STANDARD 11)

add_executable(APD main.cpp Automat.cpp Automat.h Tranzitie.cpp Tranzitie.h)