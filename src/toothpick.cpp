#include <vector>
#include <iostream>
#include "toothpick.h"
#include "sketch.h"

Toothpick::Toothpick(int x, int y, int d, Sketch* sketch): sketch(sketch) {
  if (d == 1) {
    ax = x - 4;
    bx = x + 4;
    ay = by = y;
  } else {
    ax = bx = x;
    ay = y - 4;
    by = y + 4;
  }
  blocked = false;
  dir = d;
}

void Toothpick::update() {
  if (blocked) return;

  const std::vector<Toothpick*> *others = sketch->getToothPicks();
  bool aIntersected = false;
  bool bIntersected = false;

  for (std::vector<Toothpick*>::const_iterator it = others->begin(), end = others->end(); it != end; ++it) {
    if (*it != this) {
      if ((*it)->intersects(ax, ay)) {
        aIntersected = true;
      }
      if ((*it)->intersects(bx, by)) {
        bIntersected = true;
      }
    }
  }

  if (!aIntersected) {
    sketch->addToothpick(new Toothpick(ax, ay, dir * -1, sketch));
  }

  if (!bIntersected) {
    sketch->addToothpick(new Toothpick(bx, by, dir * -1, sketch));
  }

  blocked = true;
}

bool Toothpick::intersects(int x, int y) const {
  return (ax == x && ay == y) || (bx == x && by == y);
}

void Toothpick::draw(SDL_Renderer* renderer) const {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderDrawLine(renderer, ax, ay, bx, by);
}

