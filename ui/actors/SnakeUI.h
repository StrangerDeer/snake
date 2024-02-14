#pragma once

#include <SDL.h>
#include <memory>
#include <string>
#include <utility>
#include "../../logic/actors/Snake.h"
#include "../TextureCreator.h"

class SnakeUI : public TextureCreator {
 public:
  SnakeUI(SDL_Renderer* renderer, std::shared_ptr<Snake> snake) :
  snake(std::move(snake)),
  TextureCreator(renderer, 10, 10, {0,255,0,255})
  {}
  void print(SDL_Renderer* renderer)override;

 private:
  std::shared_ptr<Snake> snake;
  const int snakePixelSize{10};
  const SDL_Color snakeColor{0,255,0,255};
};
