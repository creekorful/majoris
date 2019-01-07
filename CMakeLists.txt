cmake_minimum_required(VERSION 3.13)
project(majoris)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules)

find_package(SFML REQUIRED COMPONENTS graphics window system)

include_directories(${SFML_INCLUDE_DIR})

add_executable(majoris Source/main.cpp
        Source/Engine/GameEngine.h Source/Engine/GameEngine.cpp
        Source/Engine/Common/Updateable.h
        Source/Engine/GameObject/GameObject.h Source/Engine/GameObject/GameObject.cpp
        Source/Engine/GameObject/Component.h Source/Engine/GameObject/Component.cpp
        Source/Engine/State/GameState.h Source/Engine/State/GameState.cpp
        Source/Engine/Utils/RandomNumberGenerator.h Source/Engine/Utils/RandomNumberGenerator.cpp)

target_link_libraries(majoris ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})