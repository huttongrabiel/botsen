cmake_minimum_required(VERSION 3.25)

set(CMAKE_EXPORT_COMPILE_COMMANDS on)
set(CMAKE_CXX_STANDARD 20)

project(
    Botsen
    VERSION 0.1.0
    LANGUAGES CXX)

set(CMAKE_CXX_FLAGS)

add_library(BotsenCore SHARED
    ${CMAKE_CURRENT_SOURCE_DIR}/object.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/raylibCircleExt.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/collisions.cpp
    )
target_include_directories(BotsenCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(Botsen ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_link_libraries(Botsen BotsenCore raylib)

