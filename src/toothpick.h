#ifndef __TOOTHPICK_H
#define __TOOTHPICK_H

#include <SDL2/SDL.h>

class Sketch;

class Toothpick {
public:
  Toothpick(int x, int y, int dir, Sketch* sketch);
  void update();
  void draw(SDL_Renderer* renderer) const;
private:
  int ax;
  int ay;
  int bx;
  int by;
  int dir;
  bool blocked;
  Sketch* sketch;

  bool intersects(int x, int y) const;
};

#endif
