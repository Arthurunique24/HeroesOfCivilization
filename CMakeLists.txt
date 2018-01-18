cmake_minimum_required(VERSION 3.6)
project(HeroesOfCivilization)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

set(SOURCE_FILES src/main.cpp src/Map.cpp src/Map.h src/MapCell.cpp src/MapCell.h src/GameContext.h src/ResourceManager/ResourceIdentifier.h src/ResourceManager/ResourceHolder.h src/Constants.h src/Game.cpp src/Game.h src/Camera.cpp src/Camera.h src/GameState.cpp src/GameState.h src/PauseState.cpp src/PauseState.h src/StateManager.cpp src/StateManager.h src/State.cpp src/State.h src/GameStates.h)
add_executable(HeroesOfCivilization ${SOURCE_FILES})

SET (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
FIND_PACKAGE(SFML 2 REQUIRED system window graphics network audio)

INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SFML_LIBRARIES})