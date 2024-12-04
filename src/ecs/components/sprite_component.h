#include <SDL2/SDL_image.h>

struct SpriteComponent {
  SDL_Rect src;
  SDL_Rect dest;
  SDL_Texture *texture;
};
