#pragma once

using Entity = unsigned short;
static constexpr Entity MAX_ENTITIES = 65535;

using ComponentId = unsigned char;
inline ComponentId getComponentId() {
  static ComponentId lastId = 0;
  return lastId++;
}

template <typename T> inline ComponentId getComponentId() noexcept {
  static ComponentId typeId = getComponentId();
  return typeId;
}

using Signature = unsigned int;
constexpr unsigned int BITS_IN_SIGNATURE = sizeof(Signature) * 8;
