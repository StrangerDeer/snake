#pragma once

#include <vector>
#include <algorithm>
#include <memory>
#include "Layer.h"
#include "texts/GameText.h"

class InformationLayer : public Layer {
 public:
  InformationLayer(SDL_Renderer* renderer, int width, int height, int x, int y, SDL_Color color) :
  Layer(renderer, width, height, x,y,color)
  {}

  void print(SDL_Renderer* renderer) override;
  void addText(std::shared_ptr<GameText> text);

 private:
  std::vector<std::shared_ptr<GameText>> texts;
};
