cmake_minimum_required(VERSION 3.15)
project(unit_tests)


set(Sources src/uriTests.cpp)

add_executable(${PROJECT_NAME} ${Sources})

target_link_libraries(${PROJECT_NAME} PUBLIC gtest_main UniformResourceIdentifier)

