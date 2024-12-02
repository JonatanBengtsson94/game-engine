#ifndef GAME_H
#define GAME_H

#include "game_object_manager.h"
#include <SDL2/SDL_render.h>

class Game {
public:
  Game();
  ~Game();

  static SDL_Renderer *renderer;
  bool init(const char *title, int xpos, int ypos, int width, int height,
            bool fullscreen);
  void handleEvents();
  void update();
  void render();
  void clean();
  bool running();

private:
  bool isRunning;
  SDL_Window *window;
  GameObjectManager objectManager;
};

#endif
