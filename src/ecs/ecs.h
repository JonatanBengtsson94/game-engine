#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <memory>
#include <vector>

Class Component;
Class Entity;

using ComponentId = std::size_t;

inline ComponentId getComponentId() {
  static ComponentId lastId = 0;
  return lastId++;
}

template <typename T> inline ComponentId getComponentId() noexcept {
  static ComponentId typeId = getComponentId();
  return typeId;
}

constexpr std::size_t maxComponents = 16;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component *, maxComponents>;

class Component {
public:
  Entity *entity;
};
