#include "game_object_manager.h"

void GameObjectManager::addGameObject(GameObject *obj) {
  gameObjects.push_back(obj);
}

void GameObjectManager::update() {
  for (auto &obj : gameObjects) {
    obj->update();
  }
}

void GameObjectManager::render() {
  for (auto &obj : gameObjects) {
    obj->render();
  }
}
