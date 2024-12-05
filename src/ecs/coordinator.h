#pragma once

#include "component_manager.h"
#include "entity_manager.h"
#include "system_manager.h"

class Coordinator {
public:
  Coordinator() {
    componentManger = new ComponentManager();
    entityManager = new EntityManager();
    systemManager = new SystemManager();
  }

  ~Coordinator() {
    delete componentManger;
    delete entityManager;
    delete systemManager;
  }

  Entity createEntity() { return entityManager->createEntity(); }

  template <typename T> void addComponent(Entity entity, const T &component) {
    ComponentId componentId = getComponentId<T>();
    componentManger->addComponent(entity, component, componentId);
    Signature signature = entityManager->getSignature(entity);
    signature |= (1 << componentId);
    entityManager->setSignature(entity, signature);
    systemManager->entitySignatureChanged(entity, signature);
  }

private:
  ComponentManager *componentManger;
  EntityManager *entityManager;
  SystemManager *systemManager;
};
