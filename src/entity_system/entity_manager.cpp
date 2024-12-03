#include "entity_manager.h"

Entity EntityManager::nextEntityId = 0;

Entity EntityManager::createEntity() {
  if (nextEntityId >= MAX_ENTITIES) {
    // TODO: Throw some error
    return MAX_ENTITIES;
  }
  return nextEntityId++;
}

void EntityManager::destroyEntity(Entity entity) {
  // TODO
}

void EntityManager::setSignature(Entity entity, Signature signature) {}

Signature EntityManager::getSignature(Entity entity) {
  return signatures[entity];
}
