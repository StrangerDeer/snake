#pragma once

#include <memory>
#include <utility>
#include <iostream>
#include <string>
#include "BoardRule.h"
#include "../items/Item.h"
#include "../actors/Snake.h"

class SnakeReachItem : public BoardRule {

 public:
  SnakeReachItem(std::shared_ptr<Item> item, std::shared_ptr<Snake> snake) :
  item(std::move(item)), snake(std::move(snake))
  {}
  bool condition() override;
  void execute() override;

 private:
  std::shared_ptr<Snake> snake;
  std::shared_ptr<Item> item;
  const static int movementRange{5};
};
