#pragma once

#include <array>
#include <bitset>
#include <vector>

class Component;

using Entity = std::uint32_t;
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

constexpr std::size_t maxComponnents = 32;
using Signature = std::bitset<maxComponnents>;
using ComponentArray = std::array<Component *, maxComponnents>;

class EntityManager {
public:
  Entity createEntity();
  void destroyEntity(Entity entity);
  void setSignature(Entity entity, Signature signature);
  Signature getSignature(Entity entity);

private:
  std::vector<Entity> entities;
  std::array<Signature, MAX_ENTITIES> signatures;
  static Entity nextEntityId;
};
