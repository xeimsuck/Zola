# Echo
## Sources
file(GLOB_RECURSE echo_SOURCES
    "echo/*.cpp")
## Build
add_executable(echo ${echo_SOURCES})
## Dependencies
target_link_libraries(echo Zola)