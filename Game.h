#pragma once

#include <SDL.h>

#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <iostream>
#include <memory>

#include "logic/RandomNumber.h"
#include "logic/DirectionEnum.h"
#include "logic/items/Apple.h"
#include "logic/actors/Snake.h"
#include "ui/layers/Layer.h"
#include "ui/layers/InformationLayer.h"
#include "ui/layers/texts/SnakePointDynamicText.h"
#include "ui/actors/SnakeUI.h"
#include "ui/items/AppleUI.h"
#include "logic/Board.h"
#include "logic/boardRules/SnakeReachBoardTopEdge.h"
#include "logic/boardRules/SnakeReachBoardBottomEdge.h"
#include "logic/boardRules/SnakeReachBoardRightEdge.h"
#include "logic/boardRules/SnakeReachBoardLeftEdge.h"
#include "logic/boardRules/SnakeReachItem.h"
#include "logic/boardRules/SnakeTouchItself.h"

template<typename T>
using shared_vector = std::vector<std::shared_ptr<T>>;

class Game {

 public:
  Game() : window(nullptr), renderer(nullptr), snake(nullptr), apple(nullptr)
  {
    init();
    initLayers();
    initItems();
    initTexts();
    initRules();
  };

  void run();

 private:
  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Event event{};

  int bestScorePoint{0};
  bool isRunning{true};

  const static int boardWidth{1000};
  const static int boardHeight{1000};
  const static int informationLayerWidth{static_cast<int>(boardWidth * 0.20)};
  const static int windowWidth{boardWidth + informationLayerWidth};
  const static int windowHeight{boardHeight};
  const static int pixelSize{10};
  const static int snakeStartPositionWidth{boardWidth / 2 + informationLayerWidth};
  const static int snakeStartPositionHeight{boardHeight / 2};

  int prevPressedButton{-1};
  SDL_KeyCode down{SDLK_DOWN};
  SDL_KeyCode up{SDLK_UP};
  SDL_KeyCode left{SDLK_LEFT};
  SDL_KeyCode right{SDLK_RIGHT};

  std::unique_ptr<Layer> boardUI{nullptr};
  std::unique_ptr<InformationLayer> informationUI{nullptr};
  std::unique_ptr<SnakeUI> snakeUI{};
  std::unique_ptr<AppleUI> appleUI{};

  std::shared_ptr<Board> boardLogic{nullptr};
  std::shared_ptr<Snake> snake{nullptr};
  std::shared_ptr<Apple> apple{nullptr};

  void init();
  void initTexts();
  void initItems();
  void initLayers();
  void initRules();

  void loadTextsForInformationLayer(const shared_vector<GameText>& texts);
  void loadRules(const shared_vector<BoardRule>& boardRules);

  void handleKeyEvents();
  void drawGame();

};
