#ifndef __SKETCH_H
#define __SKETCH_H

#include <SDL2/SDL.h>
#include <vector>
#include "toothpick.h"

class Sketch {
private:
  SDL_Window *window;
  SDL_Renderer *renderer;
  bool initialized;
  bool running;
  std::vector<Toothpick*> toothpicks;

  void processInput();
  void update();
  void draw() const;

public:
  Sketch();
  bool init();
  void run();
  void quit();
  void addToothpick(Toothpick* toothpick);
  inline const std::vector<Toothpick*>* getToothPicks() const { return &toothpicks; }
};

#endif
