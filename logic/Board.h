#pragma once

#include <SDL.h>
#include <vector>
#include <memory>
#include <iostream>
#include "boardRules/BoardRule.h"

class Board {
 public:
  Board(int width, int height, int x, int y) :
      boardRect({x,y,width, height})
  {}

  SDL_Rect boardRect;

  void checkRules();

  void addRule(std::shared_ptr<BoardRule> boardRule);

 private:
  std::vector<std::shared_ptr<BoardRule>> rules;
};
