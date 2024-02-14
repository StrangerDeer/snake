#pragma once

#include <string>
#include "SnakeUI.h"

void SnakeUI::print(SDL_Renderer *renderer) {
  std::deque<std::shared_ptr<SDL_Rect>> snakeBody = snake->getSnakeBody();

  std::for_each(snakeBody.begin(), snakeBody.end(), [&](const std::shared_ptr<SDL_Rect>& snakeSegment){

    if(!snakeSegment){
      std::cerr << "Error: Snake body has nullptr!" << std::endl;
      SDL_Quit();
      return;
    }

//    if(snakeSegment->y == NULL){
//      std::cerr << "Error: Snake body part doesn't have y coordinate!" << std::endl;
//    }
//    if(snakeSegment->x == NULL){
//      std::cerr << "Error: Snake body part doesn't have x coordinate!" << std::endl;
//    }

    SDL_QueryTexture(texture, nullptr, nullptr, &snakeSegment->w, &snakeSegment->h);

    SDL_RenderCopy(renderer, texture, nullptr, snakeSegment.get());
  });
}

