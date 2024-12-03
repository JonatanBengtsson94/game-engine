#include "entity_manager.h"
#include <iostream>

Entity EntityManager::createEntity() {
  if (activeEntitiesCount >= MAX_ENTITIES) {
    std::cerr << "Error: Maximum number of entities reached." << std::endl;
    return MAX_ENTITIES;
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
