#include <SDL2/SDL_image.h>

struct sprite_component {
  SDL_Rect src;
  SDL_Rect dst;
  SDL_Texture *texture;
};

struct transform_component {
  float x, y, xVelocity, yVelocity;
};
