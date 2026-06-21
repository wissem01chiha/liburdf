#ifndef INCLUDE_URDF_CORE_ENTITY_H_
#define INCLUDE_URDF_CORE_ENTITY_H_

// Copyright 2024-2026 Wissem CHIHA

#include <vector>

#include "common/object_base.h"
#include "core/model.h"
#include "core/pose.h"

/**
 * @brief Base class for all subObjects in a world
 */
template <typename... PropertyBase>
class Entity : public ObjectBase {
 public:
  void clear() override;

 private:
  std::shared_ptr<Model> model;
  Pose origin;
};

#endif  // INCLUDE_URDF_CORE_ENTITY_H_