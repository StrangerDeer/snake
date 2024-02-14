#pragma once

#include "SnakeReachBoardRightEdge.h"

bool SnakeReachBoardRightEdge::condition() {
  return snake->getSnakeHeadXCoordinate() > board->boardRect.x + board->boardRect.w;
}

void SnakeReachBoardRightEdge::execute() {
  snake->setSnakeHeadXCoordinate(board->boardRect.x);
}

