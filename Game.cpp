#include "Game.h"

void Game::init() {
  window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth,windowHeight,SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_OPENGL);
  if (!window) {
    std::cerr << "Error: Unable to create window!" << SDL_GetError() << std::endl;
    return;
  }
  renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED);

  if (!renderer) {
    std::cerr << "Error: Unable to create renderer!" << SDL_GetError() << std::endl;
    return;
  }
}

void Game::initLayers() {
  SDL_Color informationLayerColor{1,50,32,255};
  SDL_Color boardColor{0,0,0,255};

  boardUI = std::make_unique<Layer>(renderer, boardWidth, boardHeight, informationLayerWidth, 0, boardColor);
  informationUI = std::make_unique<InformationLayer>(renderer, informationLayerWidth, boardHeight, 0, 0, informationLayerColor);

  boardLogic = std::make_shared<Board>(boardWidth, boardHeight, informationLayerWidth, 0);

}

void Game::initTexts() {
  std::string fontPath{"../ui/textures/font/Goldeneye.ttf"};
  int textSize{25};
  SDL_Color textColor{255, 255, 255, 255};

  std::string bestScoreMessage{"Best Score: "};
  int bestScoreTextWidth{10};
  int bestScoreTextHeight{10};

  int bestPointTextWidth = 155;
  int bestPointTextHeight = 10;

  std::string scoreMessage{"SCORE:"};
  int scoreTextWidthPosition{10};
  int scoreTextHeightPosition{50};

  int pointTextWidth{90};
  int pointTextHeight{50};

  shared_vector<GameText> texts = {
      std::make_shared<GameText>(renderer, fontPath, textSize,
                                 bestScoreMessage, textColor, bestScoreTextWidth, bestScoreTextHeight),
      std::make_shared<GameText>(renderer, fontPath, textSize, std::to_string(bestScorePoint),
                                 textColor, bestPointTextWidth, bestPointTextHeight),
      std::make_shared<GameText>(renderer, fontPath, textSize, scoreMessage, textColor, scoreTextWidthPosition, scoreTextHeightPosition),
      std::make_shared<SnakePointDynamicText>(renderer, fontPath, textSize, snake, textColor, pointTextWidth, pointTextHeight)
  };

  loadTextsForInformationLayer(texts);

}

void Game::loadTextsForInformationLayer(const shared_vector<GameText>& texts) {
  for(const std::shared_ptr<GameText>& text : texts){
    informationUI->addText(text);
  }
}

void Game::initItems() {
  snake = std::make_shared<Snake>(snakeStartPositionWidth, snakeStartPositionHeight,1,3,pixelSize);
  apple = std::make_shared<Apple>(informationLayerWidth, boardWidth, 0, boardHeight, pixelSize, snake);
  snakeUI = std::make_unique<SnakeUI>(renderer, snake);
  appleUI = std::make_unique<AppleUI>(renderer, apple);
}


void Game::initRules() {
  shared_vector<BoardRule> boardRules = {
      std::make_shared<SnakeReachBoardTopEdge>(snake, boardLogic),
      std::make_shared<SnakeReachBoardBottomEdge>(snake, boardLogic),
      std::make_shared<SnakeReachBoardRightEdge>(snake, boardLogic),
      std::make_shared<SnakeReachBoardLeftEdge>(snake, boardLogic),
      std::make_shared<SnakeReachItem>(apple, snake),
      std::make_shared<SnakeTouchItself>(snake)
  };

  loadRules(boardRules);
}

void Game::loadRules(const shared_vector<BoardRule>& boardRules) {
  for(const std::shared_ptr<BoardRule>& rule : boardRules){
    boardLogic->addRule(rule);
  }
}

void Game::run() {
  while (isRunning){
    handleKeyEvents();

    snake->move();

    boardLogic->checkRules();

    snake->collisions();

    drawGame();

   SDL_Delay(25);
  }
}

void Game::handleKeyEvents() {

  while (SDL_PollEvent(&event)){
    if(event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE){
      isRunning = false;
    }

    if(event.key.keysym.sym == down && prevPressedButton != UP) { snake->changeSnakeDirection(DOWN); prevPressedButton = DOWN;}
    if(event.key.keysym.sym == up && prevPressedButton != DOWN) { snake->changeSnakeDirection(UP); prevPressedButton = UP;}
    if(event.key.keysym.sym == left && prevPressedButton != RIGHT) { snake->changeSnakeDirection(LEFT); prevPressedButton = LEFT;}
    if(event.key.keysym.sym == right && prevPressedButton != LEFT) { snake->changeSnakeDirection(RIGHT); prevPressedButton = RIGHT;}

  }
}
//
//bool Game::snakeReachSnakeBody() {
//
//}

void Game::drawGame() {

  SDL_RenderClear(renderer);

  boardUI->print(renderer);
  informationUI->print(renderer);
  snakeUI->print(renderer);
  appleUI->print(renderer);

  SDL_RenderPresent(renderer);

}


