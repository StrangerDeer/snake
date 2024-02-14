#pragma once

#include "Board.h"

void Board::addRule(std::shared_ptr<BoardRule> boardRule) {
  rules.emplace_back(std::move(boardRule));
}

void Board::checkRules() {
  std::for_each(rules.begin(), rules.end(),[&](const std::shared_ptr<BoardRule>& rule) {
    if(rule->condition()){
      rule->execute();
    }
  });
}

