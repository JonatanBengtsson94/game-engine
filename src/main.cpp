#include "./ecs/components/sprite_component.h"
#include "./ecs/coordinator.h"
#include "./ecs/systems/render_system.h"
#include "ecs/types.h"
#include "game.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_video.h>

Game *game = NULL;

int main() {
  game = new Game("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800,
                  800, false);

  Coordinator *coordinator = new Coordinator();
  // Entity
  Entity racket = coordinator->createEntity();
  // Component
  SpriteComponent racketSpriteComponent;
  racketSpriteComponent.texture =
      IMG_LoadTexture(game->renderer, "./assets/racket.png");
  coordinator->addComponent(racket, racketSpriteComponent);

  while (game->running()) {
    game->handleEvents();
    game->update();
    game->render();
  }

  delete coordinator;
  delete game;

  return 0;
}
