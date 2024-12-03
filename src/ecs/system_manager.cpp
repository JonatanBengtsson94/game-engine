#include "system_manager.h"

template <typename T> T *SystemManager::RegisterSystem() {
  const char *typeName = typeid(T).name();
  auto system = new T();
  systems.insert({typeName, system});
}

template <typename T> void SystemManager::SetSignature(Signature signature) {
  const char *typeName = typeid(T).name();
  signatures.insert({typeName, signature});
}

void SystemManager::EntityDestoyed(Entity entity) {}
