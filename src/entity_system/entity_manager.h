#pragma once

#include <array>
#include <bitset>
#include <deque>

class Component;

using Entity = unsigned short;
const Entity MAX_ENTITIES = 5000;

using ComponentId = std::uint8_t;
inline ComponentId getComponentId() {
  static ComponentId lastId = 0;
  return lastId++;
}

template <typename T> inline ComponentId getComponentId() noexcept {
  static ComponentId typeId = getComponentId();
  return typeId;
}

constexpr unsigned char MAX_COMPONENTS = 32;
using Signature = std::bitset<MAX_COMPONENTS>;
using ComponentArray = std::array<Component *, MAX_COMPONENTS>;

class EntityManager {
public:
  Entity createEntity();
  void destroyEntity(Entity entity);
  void setSignature(Entity entity, Signature signature);
  Signature getSignature(Entity entity);

private:
  std::bitset<MAX_ENTITIES> avaliableEntities;
  Signature signatures[MAX_COMPONENTS];
  unsigned short activeEntitiesCount;
};
