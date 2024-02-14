#pragma once

#include <memory>
#include "../actors/Snake.h"
#include "BoardRule.h"
#include "../Board.h"

class SnakeReachBoardRightEdge : public BoardRule {

 public:
  SnakeReachBoardRightEdge(std::shared_ptr<Snake> snake, std::shared_ptr<Board> board) :
  snake(snake), board(board)
  {}

  bool condition() override;
  void execute() override;

 private:
  std::shared_ptr<Snake> snake;
  std::shared_ptr<Board> board;
};