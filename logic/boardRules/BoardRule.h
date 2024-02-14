#pragma once

#include "../actors/Snake.h"

class BoardRule {
 public:
  virtual bool condition() = 0;
  virtual void execute() = 0;
};