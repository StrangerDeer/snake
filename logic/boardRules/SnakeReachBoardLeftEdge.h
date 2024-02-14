#pragma once

#include <memory>
#include "BoardRule.h"
#include "../Board.h"

class SnakeReachBoardLeftEdge : public BoardRule {

    public:
    SnakeReachBoardLeftEdge(std::shared_ptr<Snake> snake, std::shared_ptr<Board> board) :
    snake(snake), board(board)
    {}

    bool condition() override;
    void execute() override;

    private:
    std::shared_ptr<Snake> snake;
    std::shared_ptr<Board> board;

};
