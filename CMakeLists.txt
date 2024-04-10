cmake_minimum_required(VERSION 3.0)
project(Buses)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(Buses ${SOURCES} "src/city.cpp" "src/crossRoad.cpp")