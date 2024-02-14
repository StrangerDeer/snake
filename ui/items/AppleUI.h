#pragma once

#include <utility>

#include "../TextureCreator.h"
#include "../../logic/items/Apple.h"

class AppleUI  : public TextureCreator {

 public:
  AppleUI(SDL_Renderer* renderer, std::shared_ptr<Apple> apple) :
  apple(std::move(apple)),
  TextureCreator(renderer,10, 10, {255,0,0,255})
  {}
  void print(SDL_Renderer* renderer) override;

 private:
  std::shared_ptr<Apple> apple;
};
