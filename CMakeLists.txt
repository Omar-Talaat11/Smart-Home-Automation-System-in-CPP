cmake_minimum_required(VERSION 3.10)
project(SmartHome)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add your include and source directories
include_directories(include)

file(GLOB SOURCES src/*.cpp)

# Explicitly tell CMake it’s a console app
add_executable(SmartHome ${SOURCES})
