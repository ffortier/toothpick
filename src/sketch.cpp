#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
#include "sketch.h"

Sketch::Sketch() {
  window = NULL;
  renderer = NULL;
  initialized = false;
  running = false;
}

bool Sketch::init() {
  if (initialized) {
    return false;
  }

  if (SDL_Init(SDL_INIT_EVERYTHING)) {
    return false;
  }

  window = SDL_CreateWindow(
    "Toothpick",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    800,
    800,
    SDL_WINDOW_BORDERLESS);

  if (window == NULL) {
    return false;
  }

  renderer = SDL_CreateRenderer(
    window,
    0,
    SDL_RENDERER_ACCELERATED
  );

  if (renderer == NULL) {
    return false;
  }

  return initialized = true;
}

void Sketch::quit() {
  for (auto it = toothpicks.begin(); it != toothpicks.end(); ++it) {
    delete *it;
  }

  toothpicks.clear();

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void Sketch::addToothpick(Toothpick* toothpick) {
  toothpicks.push_back(toothpick);
}

void Sketch::run() {
  running = true;

  while (running) {
    processInput();
    update();
    draw();

    SDL_Delay(1000 / 60);
  }
}

void Sketch::processInput() {
  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        running = false;
        break;
    }
  }
}

void Sketch::update() {
  for (auto it = toothpicks.begin(), end = toothpicks.end(); it != end; ++it) {
    (*it)->update();
  }
}

void Sketch::draw() const {
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderClear(renderer);

  for (auto it = toothpicks.begin(), end = toothpicks.end(); it != end; ++it) {
    (*it)->draw(renderer);
  }

  SDL_RenderPresent(renderer);
}
