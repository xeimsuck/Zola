cmake_minimum_required(VERSION 3.28)
project(Zola VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

if(${EXAMPLES})
    add_subdirectory(examples)
endif ()
add_subdirectory(Zola)