#include "game_object.h"
#include "game.h"
#include <SDL2/SDL_image.h>
#include <iostream>

GameObject::GameObject(const char *textureSheet) {
  texture = IMG_LoadTexture(Game::renderer, textureSheet);

  if (texture == NULL) {
    std::cerr << "Error loading texture: " << SDL_GetError() << std::endl;
  }
}

void GameObject::update(float deltaTime) {}

void GameObject::render() {
  SDL_RenderCopy(Game::renderer, texture, &srcRect, &destRect);
}
