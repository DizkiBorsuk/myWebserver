cmake_minimum_required(VERSION 3.15)
project(UniformResourceIdentifier LANGUAGES C CXX)

set(Headers include/URI/URI.hpp)

set(Sources src/URI.cpp)

add_library(${PROJECT_NAME} STATIC ${Sources} ${Headers})
#set_target_properties(${PROJECT_NAME} )

target_include_directories(${PROJECT_NAME} PUBLIC include)
add_subdirectory(unit_tests)