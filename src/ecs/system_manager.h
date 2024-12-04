#pragma once

#include "types.h"
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
