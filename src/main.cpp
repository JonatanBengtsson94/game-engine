#include "game.h"
#include <SDL2/SDL_video.h>

Game *game = NULL;

int main() {
  game = new Game();

  if (!game->init("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800,
                  800, false)) {
    return 1;
  }

  while (game->running()) {
    game->handleEvents();
    game->update();
    game->render();
  }

  game->clean();

  return 0;
}
