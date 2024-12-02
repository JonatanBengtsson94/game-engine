#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

class GameObject {
public:
  GameObject(const char *textureSheet);
  ~GameObject();

  void update();
  void render();

private:
  int x, y;

  SDL_Texture *texture;
  SDL_Rect srcRect, destRect;
};

#endif
