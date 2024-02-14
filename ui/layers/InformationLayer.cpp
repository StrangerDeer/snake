#pragma once

#include "InformationLayer.h"

void InformationLayer::print(SDL_Renderer *renderer) {
  SDL_QueryTexture(texture, nullptr, nullptr, &layerRect.w, &layerRect.h);

  SDL_RenderCopy(renderer, texture, nullptr, &layerRect);

  if(!texts.empty()){
    for(const std::shared_ptr<GameText>& text : texts ){
      text->display(renderer);
    }
  }
}

void InformationLayer::addText(std::shared_ptr<GameText> text) {
  texts.push_back(text);
}

