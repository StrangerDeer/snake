#pragma once

#include <SDL.h>
#include <iostream>
#include "../TextureCreator.h"


class Layer : public TextureCreator {
 public:
  Layer(SDL_Renderer* renderer, int width, int height, int x, int y, SDL_Color color) :
  TextureCreator(renderer, width, height, color)
  {
    placeLayer(x,y);
  }

  void print(SDL_Renderer* renderer) override;

 protected:
  SDL_Rect layerRect{0,0,0,0};
  void placeLayer(int x, int y);

};
