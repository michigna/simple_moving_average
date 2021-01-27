cmake_minimum_required(VERSION 3.5)

project(simple_moving_average LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    main.cpp)

set(HEADERS
    simplemovingaverage.h)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
