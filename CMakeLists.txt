cmake_minimum_required(VERSION 3.28)
project(Zola VERSION 0.1 LANGUAGES CXX DESCRIPTION "Library for working with telegram api")

set(CMAKE_CXX_STANDARD 23)

if(${BUILD_EXAMPLES})
    add_subdirectory(examples)
endif ()
add_subdirectory(Zola)