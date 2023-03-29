cmake_minimum_required(VERSION 3.10)
project(qt-genie VERSION 1.0)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS Widgets REQUIRED)

if (APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14") #For OSX
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++") #For Ubuntu
endif (APPLE)

add_subdirectory(genieutils EXCLUDE_FROM_ALL)
include_directories(
        "genieutils/include"
        "."
)

add_executable(
    qt-genie
    main.cpp
    mainwindow.cpp
    ids.h
    qt-genie.qrc
)
set_property(TARGET qt-genie PROPERTY CXX_STANDARD 17)


target_link_libraries(qt-genie genieutils Qt5::Widgets)
