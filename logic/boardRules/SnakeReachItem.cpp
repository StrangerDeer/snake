#pragma once

#include "SnakeReachItem.h"

bool SnakeReachItem::condition() {
  bool condition1 = snake->getSnakeHeadXCoordinate() >= item->getItemXCoordinate() - movementRange &&
      snake->getSnakeHeadXCoordinate() <= item->getItemXCoordinate() + movementRange;
  bool condition2 = snake->getSnakeHeadYCoordinate() >= item->getItemYCoordinate() - movementRange &&
      snake->getSnakeHeadYCoordinate() <= item->getItemYCoordinate() + movementRange;

  return condition1 && condition2;
}

void SnakeReachItem::execute() {
  item->effect();
}

