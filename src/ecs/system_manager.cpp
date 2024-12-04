#include "system_manager.h"

SystemId lastSystemId = 0;

template <typename T> SystemId SystemManager::getSystemId() noexcept {
  static SystemId typeId = generateSystemId();
  return typeId;
}

SystemId generateSystemId() { return lastSystemId++; }

void SystemManager::setSignature(SystemId system, Signature signature) {
  systemSignatures[system] = signature;
}

Signature SystemManager::getSignature(SystemId system) {
  return systemSignatures[system];
}
