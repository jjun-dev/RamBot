cmake_minimum_required(VERSION 3.22)

project(RamBot VERSION 1.0 DESCRIPTION "Discord bot with cpp")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/commands.cpp
    src/basic_commands.cpp
)

find_package(DPP REQUIRED)

target_link_libraries(${PROJECT_NAME}
    ${DPP_LIBRARIES}
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${DPP_INCLUDE_DIR}
)

include_directories(
    include
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

message(STATUS "DPP_LIBRARIES=${DPP_LIBRARIES}")

