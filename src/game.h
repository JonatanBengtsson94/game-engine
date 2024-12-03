#pragma once

#include <SDL2/SDL_render.h>
#include <vector>

class GameObject;

class Game {
public:
  Game(const char *title, int x, int y, int w, int h, bool fullscreen);
  ~Game();
  static SDL_Renderer *renderer;
  bool init(const char *title, int xpos, int ypos, int width, int height,
            bool fullscreen);
  void addGameObject(GameObject *obj);
  void handleEvents();
  void update();
  void render();
  bool running();

private:
  bool isRunning;
  SDL_Window *window;
  Uint32 lastUpdate;
  std::vector<GameObject *> gameObjects;
};
