# Cmake version
cmake_minimum_required(VERSION 3.17)

# Project name
project(IndieStudio)

# Variables
set(BINARY_NAME bomberman)
set(CMAKE_CXX_STANDARD 17)

# Paths
set(RAYLIB_PATH src/Raylib)
set(ERROR_PATH src/Error)
set(CORE_PATH src/Core)
set(OBJECT_PATH src/Object)
set(SCENE_PATH src/Scene)
set(COLLIS_PATH ${OBJECT_PATH}/Collisionable)
set(UIOBJECT_PATH ${OBJECT_PATH}/UiObject)
set(BUTTON_PATH ${UIOBJECT_PATH}/Button)
set(INPUTBOX_PATH ${BUTTON_PATH}/InputBox)
set(DESTRUCT_PATH ${COLLIS_PATH}/Destructible)
set(MOVABLE_PATH ${DESTRUCT_PATH}/Movable)
set(MAP_PATH src/Map)
set(SCENE_PATH src/Scene)
set(GROUND_PATH src/Object/Ground)
set(UIGAME_PATH src/Object/UiObject/UiGame)
set(PLAYER_PATH src/Player)
set(POWERUPS_PATH ${MOVABLE_PATH}/PowerUps)
set(ANIMATOR_PATH ${MOVABLE_PATH}/Animator)
set(WALL_PATH ${COLLIS_PATH}/Wall)

# Include directories
include_directories(src)
include_directories(${MAP_PATH})
include_directories(${RAYLIB_PATH})
include_directories(${ERROR_PATH})
include_directories(${UIOBJECT_PATH})
include_directories(${CORE_PATH})
include_directories(${OBJECT_PATH})
include_directories(${SCENE_PATH})
include_directories(${COLLIS_PATH})
include_directories(${BUTTON_PATH})
include_directories(${INPUTBOX_PATH})
include_directories(${DESTRUCT_PATH})
include_directories(${MOVABLE_PATH})
include_directories(${GROUND_PATH})
include_directories(${UIGAME_PATH})
include_directories(${POWERUPS_PATH})
include_directories(${WALL_PATH})
include_directories(${PLAYER_PATH})
include_directories(${ANIMATOR_PATH})

# Source files
set(RAYLIB_SRCS
        ${RAYLIB_PATH}/Raylib.cpp
)

set(MAP_SRCS
        ${MAP_PATH}/Map.cpp)

set(ERROR_SRCS
        ${ERROR_PATH}/Error.cpp
        ${ERROR_PATH}/RaylibError.cpp
)
set(CORE_SRCS
        ${CORE_PATH}/Core.cpp
        ${CORE_PATH}/Setting.cpp
)

set(UIOBJECT_SRCS
        ${UIOBJECT_PATH}/UiObject.cpp
)

set(INPUTBOX_SRCS
        ${INPUTBOX_PATH}/InputBox.cpp
)

set(BUTTON_SRCS
        ${BUTTON_PATH}/Button.cpp
        ${BUTTON_PATH}/BoolButton.cpp
)

set(OBJECTS_SRCS
        ${OBJECT_PATH}/AObject.cpp
        ${OBJECT_PATH}/Particles.cpp
        ${OBJECT_PATH}/Particles.hpp
        ${COLLIS_PATH}/CollisionableObject.cpp
        ${COLLIS_PATH}/Wall/Wall.cpp
        ${BUTTON_PATH}/Button.cpp
        ${DESTRUCT_PATH}/DestructibleObject.cpp
        ${DESTRUCT_PATH}/DestructibleWall.cpp
        ${MOVABLE_PATH}/MovableObject.cpp
        ${MOVABLE_PATH}/Tank.cpp
        ${MOVABLE_PATH}/Cannon.cpp
        ${MOVABLE_PATH}/Bullet.cpp
        ${MOVABLE_PATH}/TankAi.cpp
        ${MOVABLE_PATH}/TankAi.hpp
        ${POWERUPS_PATH}/PowerUps.cpp
        ${ANIMATOR_PATH}/Animator.cpp
        )

set(SCENE_SRCS
        ${SCENE_PATH}/AScene.cpp
        ${SCENE_PATH}/UiScene.cpp
        ${SCENE_PATH}/SceneMenu.cpp
        ${SCENE_PATH}/SceneNewGame.cpp
        ${SCENE_PATH}/SceneOption.cpp
        ${SCENE_PATH}/ScenePause.cpp
        ${SCENE_PATH}/SceneIntro.cpp
        ${SCENE_PATH}/SceneSplash.cpp
        ${SCENE_PATH}/SceneWin.cpp
        ${SCENE_PATH}/SceneGame.cpp
        )
set(GROUND_SRCS
        ${GROUND_PATH}/Ground.cpp)

set(UIGAME_SRCS
        ${UIGAME_PATH}/LifeGame.cpp
        ${UIGAME_PATH}/BorderPlayer.cpp
        ${UIGAME_PATH}/FrameUI.cpp
        ${UIGAME_PATH}/FullSquare.cpp
        ${UIGAME_PATH}/ColorPlayer.cpp
        ${UIGAME_PATH}/TexteUi.cpp
        ${UIGAME_PATH}/Score.cpp
        ${UIGAME_PATH}/Score.hpp)

set(INDIE_SRCS
        ${RAYLIB_SRCS}
        ${ERROR_SRCS}
        ${UIOBJECT_SRCS}
        ${BUTTON_SRCS}
        ${INPUTBOX_SRCS}
        ${MAP_SRCS}
        ${CORE_SRCS}
        ${OBJECTS_SRCS}
        ${SCENE_SRCS}
        ${GROUND_SRCS}
        ${UIGAME_SRCS}
        ${PLAYER_SRCS}
        )
# Compilation
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules/)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/)

add_compile_definitions(_USE_MATH_DEFINES)

find_package(raylib REQUIRED)

add_executable(${BINARY_NAME} Main.cpp ${INDIE_SRCS})

target_compile_features(${BINARY_NAME} PRIVATE cxx_std_17)
target_link_libraries(bomberman raylib)