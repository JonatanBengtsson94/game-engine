#pragma once

#include <array>
#include <bitset>

class Component;

using Entity = unsigned short;
static constexpr Entity MAX_ENTITIES = 65535;

using ComponentId = unsigned char;
inline ComponentId getComponentId() {
  static ComponentId lastId = 0;
  return lastId++;
}

template <typename T> inline ComponentId getComponentId() noexcept {
  static ComponentId typeId = getComponentId();
  return typeId;
}

constexpr unsigned char MAX_COMPONENTS = 255;
using Signature = std::bitset<MAX_COMPONENTS>;
using ComponentArray = std::array<Component *, MAX_COMPONENTS>;

class EntityManager {
public:
  EntityManager();
  Entity createEntity();
  void destroyEntity(Entity entity);
  void setSignature(Entity entity, Signature signature);
  Signature getSignature(Entity entity);

private:
  unsigned short avaliableEntities;
  Signature signatures[MAX_COMPONENTS];
  unsigned short activeEntitiesCount;
};
