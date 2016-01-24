cmake_minimum_required(VERSION 2.6)
project(Tower_Defense)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -pedantic")

include_directories(src)
set(SOURCE_FILES src/main.cpp src/Button.cpp src/Enemy.cpp src/EnemySpawner.cpp src/Field.cpp src/Game.cpp src/GameMap.cpp src/globals.cpp src/Loader.cpp src/Other.cpp src/Particle.cpp src/Tower.cpp)
add_executable(tower_defense ${SOURCE_FILES})

target_link_libraries(tower_defense sfml-graphics)
target_link_libraries(tower_defense sfml-window)
target_link_libraries(tower_defense sfml-system)
