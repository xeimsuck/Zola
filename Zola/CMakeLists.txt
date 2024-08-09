# CURL
find_package(CURL REQUIRED)
if(NOT CURL_FOUND)
    message(FATAL_ERROR "Could not find the CURL library and development files.")
endif(NOT CURL_FOUND)

# Zola
## Sources
FILE(GLOB_RECURSE Zola_SOURCES
        "src/*.cpp")
## Build
add_library(Zola STATIC ${Zola_SOURCES})
## Dependencies
target_include_directories(Zola PUBLIC "include/" "lib/nlohmann" ${CURL_INCLUDE_DIR})
target_link_libraries(Zola PUBLIC ${CURL_LIBRARIES})