#pragma once

#include <utility>

#include "BoardRule.h"

class SnakeTouchItself : public BoardRule {

 public:
  SnakeTouchItself(std::shared_ptr<Snake> snake) :
  snake(std::move(snake))
  {}

  bool condition() override;
  void execute() override;

 private:
  std::shared_ptr<Snake> snake;
};
