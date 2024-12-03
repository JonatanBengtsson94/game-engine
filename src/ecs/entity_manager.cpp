#include "entity_manager.h"
#include <stdexcept>

EntityManager::EntityManager() {
  activeEntitiesCount = 0;
  avaliableEntities.set();
}

Entity EntityManager::createEntity() {
  if (activeEntitiesCount >= MAX_ENTITIES) {
    throw std::runtime_error("Error: Maximum of entities reached.");
  }

  Entity id = avaliableEntities._Find_first();
  avaliableEntities.reset(id);
  ++activeEntitiesCount;
  return id;
}

void EntityManager::destroyEntity(Entity entity) {
  avaliableEntities.set(entity);
  --activeEntitiesCount;
}

void EntityManager::setSignature(Entity entity, Signature signature) {}

Signature EntityManager::getSignature(Entity entity) {
  return signatures[entity];
}
