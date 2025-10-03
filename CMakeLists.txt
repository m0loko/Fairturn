cmake_minimum_required(VERSION 4.0)
project(Fairturn)

set(CMAKE_CXX_STANDARD 14)

include_directories(OPITeamProject)

add_executable(Fairturn
        OPITeamProject/Header.h
        OPITeamProject/input.cpp
        OPITeamProject/input.h
        OPITeamProject/inputFromFile.cpp
        OPITeamProject/logo.cpp
        OPITeamProject/logo.h
        OPITeamProject/main.cpp
        OPITeamProject/MENU.cpp
        OPITeamProject/menu.h
        OPITeamProject/parser.h
        OPITeamProject/parserIN.cpp
        OPITeamProject/parserOUT.cpp
        OPITeamProject/ranging.cpp
        OPITeamProject/ranging.h
        OPITeamProject/Sorting.cpp
        OPITeamProject/writeToFile.cpp)
