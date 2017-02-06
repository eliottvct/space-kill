cmake_minimum_required(VERSION 3.6)
project(SpaceKillMac)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SOURCE_FILES
        "*.hpp"
        "*.cpp")

add_executable(SpaceKillMac ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(SpaceKillMac ${SFML_LIBRARIES})
endif()