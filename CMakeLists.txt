cmake_minimum_required(VERSION 3.20)
project(badge)

set(CMAKE_CXX_STANDARD 14)

add_executable(badge main.cpp)

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
set(SFML_DIR "./SFML")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
target_link_libraries(badge sfml-graphics sfml-audio)