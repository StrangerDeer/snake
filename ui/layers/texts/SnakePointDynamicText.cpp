#pragma once
#include "SnakePointDynamicText.h"

void SnakePointDynamicText::display(SDL_Renderer *renderer) {
  if(currentValue != snake->getSnakePoint()){
    message = std::to_string(snake->getSnakePoint());
    currentValue = snake->getSnakePoint();
    loadFont();
  }
  GameText::display(renderer);
}
