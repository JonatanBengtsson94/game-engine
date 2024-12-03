#pragma once

#include "entity_manager.h"
#include <memory>
#include <unordered_map>
#include <vector>

class System {
public:
  std::vector<Entity> entities;
};

class SystemManager {
public:
  template <typename T> T *RegisterSystem();
  template <typename T> void SetSignature(Signature signature);
  void EntityDestoyed(Entity entity);

private:
  std::unordered_map<const char *, Signature> signatures;
  std::unordered_map<const char *, System *> systems;
};
