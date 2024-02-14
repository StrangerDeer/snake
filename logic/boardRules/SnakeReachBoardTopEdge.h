#pragma once

#include "BoardRule.h"
#include "../Board.h"

class SnakeReachBoardTopEdge : public BoardRule {

 public:
  SnakeReachBoardTopEdge(std::shared_ptr<Snake> snake, std::shared_ptr<Board> board) :
  snake(snake), board(board)
  {}

  bool condition() override;
  void execute() override;

 private:
  std::shared_ptr<Snake> snake;
  std::shared_ptr<Board> board;
};
