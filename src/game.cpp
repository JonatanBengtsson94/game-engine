#include "game.h"
#include "game_object.h"
#include <SDL2/SDL.h>
#include <iostream>

SDL_Renderer Game::*renderer = NULL;

Game::Game() {}
Game::~Game() {}

bool Game::init(const char *title, int xpos, int ypos, int width, int height,
                bool fullscreen) {

  int flags = 0;
  if (fullscreen) {
    flags = SDL_WINDOW_FULLSCREEN;
  }

  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    std::cerr << "Error initializing SDL: " << SDL_GetError() << std::endl;
    system("pause");
    return false;
  }

  window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
  if (!window) {
    std::cerr << "Error creating window: " << SDL_GetError() << std::endl;
    system("pause");
    return false;
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (!renderer) {
    std::cerr << "Error creating renderer: " << SDL_GetError() << std::endl;
    system("pause");
    return false;
  }

  isRunning = true;
  return true;
}

void Game::addGameObject(GameObject *obj) { gameObjects.push_back(obj); }

void Game::handleEvents() {
  SDL_Event e;

  // Event Loop
  while (SDL_PollEvent(&e) != 0) {
    if (e.type == SDL_QUIT) {
      isRunning = false;
    }
  }
}

void Game::update() {
  for (auto &obj : gameObjects) {
    obj->update();
  }
}

void Game::render() {
  SDL_RenderClear(renderer);
  for (auto &obj : gameObjects) {
    obj->render();
  }
  SDL_RenderPresent(renderer);
}

bool Game::running() { return isRunning; }

void Game::clean() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
