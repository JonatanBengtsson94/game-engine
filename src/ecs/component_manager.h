#pragma once

#include "types.h"

class ComponentManager {
public:
  template <typename T> ComponentId getComponentId() noexcept;

private:
  static ComponentId lastComponentId();
  ComponentId generateComponentId();
};
