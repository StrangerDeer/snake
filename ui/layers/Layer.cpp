#pragma once

#include "Layer.h"


void Layer::placeLayer(int x, int y) {
  layerRect.x = x;
  layerRect.y = y;
}

void Layer::print(SDL_Renderer *renderer) {
  SDL_QueryTexture(texture, nullptr, nullptr, &layerRect.w, &layerRect.h);

  SDL_RenderCopy(renderer, texture, nullptr, &layerRect);
}

