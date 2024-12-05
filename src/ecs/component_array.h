#pragma once

#include "types.h"
#include <vector>

class ComponentArrayBase {
  virtual ~ComponentArrayBase() = default;
};

template <typename T> class ComponentArray {
public:
  void insert(Entity entity, const T &component) {
    if (entity >= components.size()) {
      components.resize(entity + 1);
    }
    components[entity] = component;
  }

  T &get(Entity entity) { return components[entity]; }

  void remove(Entity entity) { components[entity] = T(); }

private:
  std::vector<T> components;
};
