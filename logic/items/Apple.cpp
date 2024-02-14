#pragma once

#include "Apple.h"


int Apple::generateRandomCoordinate(int min, int max) {
  return RandomNumber::get(min, max);
}

void Apple::generateNewPosition() {
  itemRect.x = generateRandomCoordinate(minimumX + pixelSize, maximumX - pixelSize);
  itemRect.y = generateRandomCoordinate(minimumY + pixelSize, maximumY - pixelSize);
}

void Apple::effect() {
  snake->increaseSnakeLength(increaseSnakeLengthValue);
  snake->increaseSnakePoint(increaseSnakePointValue);
  generateNewPosition();
}
