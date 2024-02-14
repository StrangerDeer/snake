#pragma once

#include "Snake.h"

void Snake::standCollision() {

}

void Snake::moveCollision() {
  for(size_t i = snakeBody.size() - 1; i > 0; --i){
    rect_ptr prev = snakeBody[i - 1];

    snakeBody[i]->y = prev->y;
    snakeBody[i]->x = prev->x;
  }
}

void Snake::move() {
  switch(snakeDirection){
    case DOWN:
      snakeHead->y += snakeSpeed;
      break;
    case UP:
      snakeHead->y -= snakeSpeed; break;
    case LEFT:
      snakeHead->x -= snakeSpeed; break;
    case RIGHT:
      snakeHead->x += snakeSpeed; break;
    default:;
  }
}

void Snake::collisions() {
  if(snakeSpeed > 0){
    moveCollision();
  } else {
    standCollision();
  }
}

void Snake::stopSnake() {
  snakeSpeed = 0;
}

void Snake::goSnake() {
    snakeSpeed = 3;
}

void Snake::increaseSnakeLength(int increaseValue) {

  if(snakeBody.size() == 1){
    for(int i = 0; i <= increaseValue; i++){
      rect_ptr snakeBodyPart = std::make_shared<SDL_Rect>(SDL_Rect {snakeHead->x + 1,snakeHead->y, 10, 10});
      snakeBody.push_back(snakeBodyPart);
    }
    return;
  }

  for(int i = 0; i <= increaseValue; i++){
    rect_ptr snakeBodyPart = std::make_shared<SDL_Rect>(SDL_Rect {snakeBody.back()->x, snakeBody.back()->y, 10, 10});
    snakeBody.push_back(snakeBodyPart);
  }
}






