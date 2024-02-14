#pragma once

#include <utility>

#include "GameText.h"
#include "../../../logic/actors/Snake.h"

class SnakePointDynamicText : public GameText{
 public:
  SnakePointDynamicText(SDL_Renderer* renderer, std::string  fontPath, int fontSize, std::shared_ptr<Snake> snake, const SDL_Color& color, int x, int y) :
  GameText(renderer, std::move(fontPath), fontSize, std::to_string(snake->getSnakePoint()), color, x,y),
  snake(snake),
  currentValue(snake->getSnakePoint())
  {}
  void display(SDL_Renderer* renderer) override;

 private:
  int currentValue;
  std::shared_ptr<Snake> snake;
};
