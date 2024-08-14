# Simple Echo
## Sources
file(GLOB_RECURSE simple_echo_SOURCES
        "simple_echo/*.cpp")
## Build
add_executable(simple_echo ${simple_echo_SOURCES})
## Dependencies
target_link_libraries(simple_echo Zola)

# Echo
## Sources
file(GLOB_RECURSE echo_SOURCES
    "echo/*.cpp")
## Build
add_executable(echo ${echo_SOURCES})
## Dependencies
target_link_libraries(echo Zola)

# Ping Button
## Sources
file(GLOB_RECURSE pinger_SOURCES
        "pinger/*.cpp")
## Build
add_executable(pinger ${pinger_SOURCES})
## Dependencies
target_link_libraries(pinger Zola)