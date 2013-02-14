project(Gogomoku)

cmake_minimum_required(VERSION 2.8)

find_package(Qt4 REQUIRED)

find_package(KDE4 REQUIRED)
include(KDE4Defaults)
include_directories(${KDE4_INCLUDES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexceptions")

add_subdirectory(src)
add_subdirectory(po)
add_subdirectory(data)
