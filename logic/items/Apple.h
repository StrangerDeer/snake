#pragma once

#include <SDL.h>
#include <memory>
#include "../RandomNumber.h"
#include "../actors/Snake.h"
#include "Item.h"

class Apple : public Item {

 public:
  Apple(int minimumX, int maximumX, int minimumY, int maximumY, int pixelSize, std::shared_ptr<Snake> snake) :
    minimumX(minimumX), maximumX(maximumX), minimumY(minimumY), maximumY(maximumY), pixelSize(pixelSize), snake(std::move(snake)),
    Item(generateRandomCoordinate(minimumX, maximumX), generateRandomCoordinate(minimumY, maximumY), pixelSize, pixelSize)
  {
  };

  void effect() override;
  void generateNewPosition();

 private:
  std::shared_ptr<Snake> snake;
  const static int increaseSnakePointValue{1};
  const static int increaseSnakeLengthValue{50};

  const int minimumX, maximumX, minimumY, maximumY, pixelSize;

  static int generateRandomCoordinate(int min, int max);
};
