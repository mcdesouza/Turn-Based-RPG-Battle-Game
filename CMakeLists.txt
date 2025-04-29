cmake_minimum_required(VERSION 3.30)
project(RPG)

set(CMAKE_CXX_STANDARD 20)

add_executable(RPG main.cpp
        Character.h
        Character.cpp
        Wizard.h
        Wizard.cpp
        Berserker.h
        Berserker.cpp
        Swordsman.h
        Swordsman.cpp)
