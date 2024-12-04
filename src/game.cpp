#include "game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdexcept>
#include <string.h>

SDL_Renderer Game::*renderer = NULL;

Game::Game(const char *title, int x, int y, int w, int h, bool fullscreen) {

  int flags = 0;
  if (fullscreen) {
    flags = SDL_WINDOW_FULLSCREEN;
  }

  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    const char *error_message = SDL_GetError();
    throw std::runtime_error("Error initializing SDL: " +
                             std::string(SDL_GetError()));
  }

  window = SDL_CreateWindow(title, x, y, w, h, flags);
  if (!window) {
    const char *error_message = SDL_GetError();
    throw std::runtime_error("Error creating window: " +
                             std::string(SDL_GetError()));
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (!renderer) {
    throw std::runtime_error("Error creating renderer: " +
                             std::string(SDL_GetError()));
  }

  lastUpdate = 0;
  isRunning = true;
}

Game::~Game() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void Game::handleEvents() {
  SDL_Event e;

  while (SDL_PollEvent(&e) != 0) {
    if (e.type == SDL_QUIT) {
      isRunning = false;
    }
  }
}

void Game::update() {
  float time = SDL_GetTicks();
  float deltaTime = (time - lastUpdate) / 1000.0f;
  lastUpdate = time;
}

void Game::render() {
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
}

bool Game::running() { return isRunning; }
