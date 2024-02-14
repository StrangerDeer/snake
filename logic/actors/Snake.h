#pragma once

#include <SDL.h>
#include <deque>
#include <algorithm>
#include <memory>
#include "../DirectionEnum.h"

using rect_ptr = std::shared_ptr<SDL_Rect>;

class Snake {
 public:
  Snake(int snakeStartPositionWidth, int snakeStartPositionHeight, int startSnakeLength, int startSnakeSpeed, int pixelSize) :
      snakeHead(std::make_shared<SDL_Rect>(SDL_Rect {snakeStartPositionWidth, snakeStartPositionHeight, pixelSize, pixelSize})),
      snakeBody({snakeHead}),
      snakeLength(startSnakeLength),
      snakeSpeed(startSnakeSpeed)
  {
  }

  int getSnakeHeadXCoordinate() const { return  snakeHead->x;}
  int getSnakeHeadYCoordinate() const {return snakeHead->y;}
  std::deque<rect_ptr> getSnakeBody() const {return snakeBody;}
  int getSnakePoint() const {return snakePoint;}
  int getSnakeLength() const {return snakeLength;}

  void setSnakeHeadXCoordinate(int newX) { snakeHead->x = newX;}
  void setSnakeHeadYCoordinate(int newY) { snakeHead->y = newY;}
  void changeSnakeDirection(DirectionEnum direction) {snakeDirection = direction;}

  void increaseSnakeLength(int increaseValue);
  void decreaseSnakeLength(int length) {snakeLength -= length;}
  void increaseSnakePoint(int num) {snakePoint += num;}

  void stopSnake();
  void goSnake();
  void collisions();
  void move();

 private:
  rect_ptr snakeHead;
  std::deque<rect_ptr> snakeBody;

  int snakeDirection{-1};
  int snakeLength;
  int snakePoint{0};
  int snakeSpeed;

  void standCollision();
  void moveCollision();

};
