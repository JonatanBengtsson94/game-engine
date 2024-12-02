#ifndef GAME_OBJECT_MANAGER_H
#define GAME_OBJECT_MANAGER_H

#include "game_object.h"
#include <vector>

class GameObjectManager {
public:
  void addGameObject(GameObject *obj);
  void update();
  void render();

private:
  std::vector<GameObject *> gameObjects;
};

#endif
