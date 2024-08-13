# CURL
find_package(CURL REQUIRED)

# nlohmann_json
find_package(nlohmann_json REQUIRED)

# Zola
## Sources
FILE(GLOB_RECURSE Zola_SOURCES
        "src/*.cpp")
## Build
add_library(Zola STATIC ${Zola_SOURCES})
## Dependencies
target_include_directories(Zola PUBLIC "include/"  ${CURL_INCLUDE_DIR})
target_link_libraries(Zola PUBLIC ${CURL_LIBRARIES} nlohmann_json::nlohmann_json)
## Installation
include(GNUInstallDirs)
set(INCLUDE_INSTALL_DIR "${CMAKE_INSTALL_INCLUDEDIR}/Zola"
        CACHE PATH "Location of header files")
include(CMakePackageConfigHelpers)
configure_package_config_file(
        "ZolaConfig.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/ZolaConfig.cmake"
        INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/Zola"
        PATH_VARS INCLUDE_INSTALL_DIR
)
write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/ZolaConfigVersion.cmake"
        VERSION 0.2
        COMPATIBILITY SameMajorVersion
)
install(TARGETS Zola
        DESTINATION "${CMAKE_INSTALL_LIBDIR}"
)
install(DIRECTORY "include/Zola/"
        DESTINATION "${INCLUDE_INSTALL_DIR}"
)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/ZolaConfig.cmake"
              "${CMAKE_CURRENT_BINARY_DIR}/ZolaConfigVersion.cmake"
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/Zola"
)