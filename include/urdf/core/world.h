#ifndef INCLUDE_URDF_CORE_WORLD_H_
#define INCLUDE_URDF_CORE_WORLD_H_

// Copyright 2024-2026 Wissem CHIHA

#include <vector>

#include "common/object_base.h"
#include "core/entity.h"
#include "core/model.h"
#include "core/pose.h"

/**
 * @brief Base class for models enviroment defintions
 */
template <typename... PropertyBase>
class World : public ObjectBase {
 public:
  World();
  void clear();

 private:
  std::shared_ptr<std::string> name = nullptr;
  std::vector<Entity<PropertyBase...>> models;
};
#endif  //  INCLUDE_URDF_CORE_WORLD_H_
