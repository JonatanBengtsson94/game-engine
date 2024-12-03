#include "entity_manager.h"
#include <stdexcept>

EntityManager::EntityManager() {
  activeEntitiesCount = 0;
  avaliableEntities = 0xFFFF;
}

Entity EntityManager::createEntity() {
  if (activeEntitiesCount >= MAX_ENTITIES) {
    throw std::runtime_error("Error: Maximum of entities reached.");
  }

  Entity id = __builtin_ctz(avaliableEntities);
  avaliableEntities &= ~(1 << id);
  ++activeEntitiesCount;
  return id;
}

void EntityManager::destroyEntity(Entity entity) {
  avaliableEntities |= (1 << entity);
  --activeEntitiesCount;
}

void EntityManager::setSignature(Entity entity, Signature signature) {}

Signature EntityManager::getSignature(Entity entity) {
  return signatures[entity];
}
