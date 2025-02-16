cmake_minimum_required(VERSION 3.15.2)

project(ProjectName)

add_subdirectory(src)
add_subdirectory(tests)

add_executable(TestName Test.cpp)
