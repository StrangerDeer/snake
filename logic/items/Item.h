#pragma once

class Item {
 public:
  Item(int x, int y, int width, int height) :
  itemRect({x,y,width,height})
  {}

  virtual void effect() = 0;

  int getItemXCoordinate() const {return itemRect.x;};
  int getItemYCoordinate() const {return itemRect.y;};

  SDL_Rect itemRect;
};