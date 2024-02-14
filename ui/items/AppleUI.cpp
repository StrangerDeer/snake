#pragma once

#include "AppleUI.h"

void AppleUI::print(SDL_Renderer *renderer) {
  SDL_QueryTexture(texture, nullptr, nullptr, &apple->itemRect.w, &apple->itemRect.h);

  SDL_RenderCopy(renderer, texture, nullptr, &apple->itemRect);
}

