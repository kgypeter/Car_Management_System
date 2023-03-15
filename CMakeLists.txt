cmake_minimum_required(VERSION 3.21)
project(Atom_L7)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Atom_L7
        controller.cpp
        controller.h
        crudrepository.cpp
        crudrepository.h
        csvfilerepository.cpp
        csvfilerepository.h
        domain.cpp
        domain.h
        inmemoryrepository.cpp
        inmemoryrepository.h
        main.cpp
        mainwindow.cpp
        mainwindow.h)
