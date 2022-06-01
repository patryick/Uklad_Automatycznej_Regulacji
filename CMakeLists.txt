cmake_minimum_required(VERSION 3.21)
project(Uklad_Automatycznej_Regulacji)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Uklad_Automatycznej_Regulacji
        POMIESZCZENIE.cpp
        POMIESZCZENIE.h Symulacja.cpp Symulacja.h main.cpp Grzejnik.cpp Grzejnik.h Regulator.h RegulatorBB.cpp RegulatorBB.h RegulatorPID.cpp RegulatorPID.h WyjatekRegulator.h)
