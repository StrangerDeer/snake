#pragma once

#include "SnakeReachBoardTopEdge.h"

bool SnakeReachBoardTopEdge::condition() {
  return snake->getSnakeHeadYCoordinate() < board->boardRect.y;
}

void SnakeReachBoardTopEdge::execute() {
  snake->setSnakeHeadYCoordinate(board->boardRect.y + board->boardRect.w);
}

