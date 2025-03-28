cmake_minimum_required(VERSION 3.30)
project(Joc_Life_Sim)

set(CMAKE_CXX_STANDARD 20)

add_executable(Joc_Life_Sim main.cpp
        User.cpp
        User.h
        Casino.cpp
        Casino.h
        Deck_Of_Cards.cpp
        Deck_Of_Cards.h
        QualityTools.cpp
        QualityTools.h)
