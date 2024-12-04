#include "./ecs/entity_manager.h"
#include "game.h"
#include <SDL2/SDL_video.h>

EntityManager *entityManager;
Game *game = NULL;

int main() {
  game = new Game("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800,
                  800, false);

  entityManager = new EntityManager();
  Entity racket = entityManager->createEntity();

  while (game->running()) {
    game->handleEvents();
    game->update();
    game->render();
  }

  delete entityManager;
  delete game;

  return 0;
}
