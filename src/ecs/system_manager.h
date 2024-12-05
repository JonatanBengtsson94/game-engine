#pragma once

#include "types.h"
#include <unordered_map>
#include <vector>

class System {
public:
  std::vector<Entity> entities;
};

class SystemManager {
public:
  void setSignature(SystemId systemId, Signature signature) {
    systemSignatures[systemId] = signature;
  }

  Signature getSignature(SystemId systemId) {
    return systemSignatures[systemId];
  }

  void entitySignatureChanged(Entity entity, Signature entitySignature) {
    for (auto const &pair : systems) {
      auto const &id = pair.first;
      auto const &system = pair.second;
      auto const &systemSignature = systemSignatures[id];

      if ((entitySignature & systemSignature) == systemSignature) {
        system->entities.push_back(entity);
      } else {
        for (auto it = system->entities.begin(); it != system->entities.end();
             ++it) {
          if (*it == entity) {
            system->entities.erase(it);
            break;
          }
        }
      }
    }
  }

private:
  Signature systemSignatures[BITS_IN_SIGNATURE];
  std::unordered_map<SystemId, System *> systems;
};
