#pragma once

#include "SnakeReachBoardBottomEdge.h"

bool SnakeReachBoardBottomEdge::condition() {
  return snake->getSnakeHeadYCoordinate() > board->boardRect.y + board->boardRect.w;
}

void SnakeReachBoardBottomEdge::execute() {
  snake->setSnakeHeadYCoordinate(board->boardRect.y);
}

