#pragma once

#include "entity_manager.h"
#include <memory>
#include <unordered_map>
#include <vector>

using SystemId = unsigned char;

class System {
public:
  std::vector<Entity> entities;
};

class SystemManager {
public:
  template <typename T> SystemId getSystemId() noexcept;
  void setSignature(SystemId system, Signature signature);
  Signature getSignature(SystemId system);

private:
  static SystemId lastSystemId;
  SystemId generateSystemId();
  Signature systemSignatures[BITS_IN_SIGNATURE];
};
