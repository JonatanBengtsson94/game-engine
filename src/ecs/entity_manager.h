#pragma once

#include "types.h"

class EntityManager {
public:
  EntityManager();
  Entity createEntity();
  void destroyEntity(Entity entity);
  void setSignature(Entity entity, Signature signature);
  Signature getSignature(Entity entity);

private:
  unsigned short avaliableEntities;
  Signature entitySignatures[MAX_ENTITIES];
  unsigned short activeEntitiesCount;
};
