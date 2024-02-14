#pragma once

#include "SnakeReachBoardLeftEdge.h"

bool SnakeReachBoardLeftEdge::condition() {
  return snake->getSnakeHeadXCoordinate() < board->boardRect.x;
}

void SnakeReachBoardLeftEdge::execute() {
  snake->setSnakeHeadXCoordinate(board->boardRect.x + board->boardRect.w);
}

