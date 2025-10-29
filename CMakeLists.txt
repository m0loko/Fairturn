cmake_minimum_required(VERSION 3.31)
project(Fairturn)

set(CMAKE_CXX_STANDARD 14)

include_directories(res)

add_executable(Fairturn
        res/Header.h
        res/input.cpp
        res/input.h
        res/inputFromFile.cpp
        res/logo.cpp
        res/logo.h
        res/main.cpp
        res/MENU.cpp
        res/menu.h
        res/parser.h
        res/parserIN.cpp
        res/parserOUT.cpp
        res/ranging.cpp
        res/ranging.h
        res/Sorting.cpp
        res/writeToFile.cpp)
