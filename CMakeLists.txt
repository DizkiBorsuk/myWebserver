cmake_minimum_required(VERSION 3.15)
project(myWebserver LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing() 

add_subdirectory(googletest)
add_subdirectory(UniformResourceIdentifier)