cmake_minimum_required(VERSION 3.15.2)

project(ProjectName)

option(WITH_TESTS "enable tests" OFF)

add_subdirectory(src)

if(WITH_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
