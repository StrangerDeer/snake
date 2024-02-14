cmake_minimum_required(VERSION 3.26)
project(Snake)

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_executable(Snake main.cpp
        Game.cpp
        Game.h
        logic/DirectionEnum.h
        logic/RandomNumber.h
        ui/layers/texts/GameText.h
        ui/layers/texts/GameText.cpp
        logic/items/Apple.cpp
        logic/items/Apple.h
        logic/actors/Snake.cpp
        logic/actors/Snake.h
        ui/layers/Layer.cpp
        ui/layers/Layer.h
        ui/layers/InformationLayer.cpp
        ui/layers/InformationLayer.h
        ui/layers/texts/SnakePointDynamicText.cpp
        ui/layers/texts/SnakePointDynamicText.h
        ui/actors/SnakeUI.cpp
        ui/actors/SnakeUI.h
        ui/TextureCreator.cpp
        ui/TextureCreator.h
        ui/items/AppleUI.cpp
        ui/items/AppleUI.h
        logic/Board.cpp
        logic/Board.h
        logic/boardRules/BoardRule.h
        logic/boardRules/SnakeReachBoardTopEdge.cpp
        logic/boardRules/SnakeReachBoardTopEdge.h
        logic/boardRules/SnakeReachBoardBottomEdge.cpp
        logic/boardRules/SnakeReachBoardBottomEdge.h
        logic/boardRules/SnakeReachBoardRightEdge.cpp
        logic/boardRules/SnakeReachBoardRightEdge.h
        logic/boardRules/SnakeReachBoardLeftEdge.cpp
        logic/boardRules/SnakeReachBoardLeftEdge.h
        logic/items/Item.h
        logic/boardRules/SnakeReachItem.cpp
        logic/boardRules/SnakeReachItem.h
        logic/boardRules/SnakeTouchItself.cpp
        logic/boardRules/SnakeTouchItself.h
)

target_link_libraries(Snake
        PRIVATE
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
        $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>
        $<IF:$<TARGET_EXISTS:SDL2_ttf::SDL2_ttf>,SDL2_ttf::SDL2_ttf,SDL2_ttf::SDL2_ttf-static>
)