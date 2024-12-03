#pragma once

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

class GameObject {
public:
  GameObject(const char *textureSheet);
  ~GameObject();

  void update(float deltaTime);
  void render();

private:
  int x, y;

  SDL_Texture *texture;
  SDL_Rect srcRect, destRect;
};
