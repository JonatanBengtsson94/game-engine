#pragma once

#include "component_array.h"
#include "types.h"
#include <unordered_map>

class ComponentManager {
public:
  template <typename T>
  void addComponent(Entity entity, const T &component,
                    ComponentId componentId) {
    getComponentArray<T>(componentId)->insert(entity, component);
  }

private:
  std::unordered_map<ComponentId, ComponentArrayBase *> componentArrays;

  template <typename T>
  ComponentArray<T> *getComponentArray(ComponentId componentId) {
    auto it = componentArrays.find(componentId);
    return static_cast<ComponentArray<T> *>(it->second);
  }
};
