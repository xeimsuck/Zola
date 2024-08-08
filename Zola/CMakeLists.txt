# CURL
find_package(CURL REQUIRED)

# Zola
## Sources
FILE(GLOB_RECURSE Zola_SOURCES
        "src/*.cpp")
## Build
add_library(Zola ${Zola_SOURCES})
## Dependencies
target_include_directories(Zola PUBLIC "include/")
target_link_libraries(Zola CURL)