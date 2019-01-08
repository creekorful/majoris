cmake_minimum_required(VERSION 3.9)
project(Majoris)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules)

find_package(SFML REQUIRED COMPONENTS graphics window system)

include_directories(${SFML_INCLUDE_DIR})

add_library(Majoris Source/Test/main.cpp
        Source/Engine/GameEngine.h Source/Engine/GameEngine.cpp
        Source/Engine/Common/Updateable.h
        Source/Engine/GameObject/GameObject.h Source/Engine/GameObject/GameObject.cpp
        Source/Engine/GameObject/Component.h Source/Engine/GameObject/Component.cpp
        Source/Engine/State/GameState.h Source/Engine/State/GameState.cpp
        Source/Engine/Utils/RandomNumberGenerator.h Source/Engine/Utils/RandomNumberGenerator.cpp
        Source/Engine/Font/FontManager.cpp Source/Engine/Font/FontManager.h Source/Test/TestState.cpp Source/Test/TestState.h Source/Engine/GameObject/Gui/Text.cpp Source/Engine/GameObject/Gui/Text.h Source/Engine/GameObject/Gui/Menu.cpp Source/Engine/GameObject/Gui/Menu.h)

target_link_libraries(Majoris ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

add_executable(majoris_test Source/Test/main.cpp)

target_link_libraries(majoris_test Majoris)