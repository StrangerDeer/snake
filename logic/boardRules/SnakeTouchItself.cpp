#pragma once

#include <iostream>
#include "SnakeTouchItself.h"

bool SnakeTouchItself::condition() {
  std::deque<std::shared_ptr<SDL_Rect>> snakeBody = snake->getSnakeBody();

  if(snakeBody.size() > 1){
    for(size_t i = snakeBody.size() - 1; i > 0; --i){
      if(snake->getSnakeHeadXCoordinate() == snakeBody[i]->x &&
            snake->getSnakeHeadYCoordinate() == snakeBody[i]->y){
        return true;
      }
    }
  }
  return false;
}

void SnakeTouchItself::execute() {
  std::cout<< "here" << std::endl;
}

