#ifndef INCLUDE_URDF_CORE_LINK_H_
#define INCLUDE_URDF_CORE_LINK_H_

// Copyright 2024-2026 Wissem CHIHA

#include "common/geometry_base.h"
#include "common/object_base.h"
#include "core/collision.h"
#include "core/inertia.h"
#include "core/material.h"
#include "core/pose.h"
#include "core/visual.h"

class Link final : public ObjectBase
{
 public:
  Link();
  bool isA(const char* name) const override;
  void getOrigin(double* pos) const;
  void setVisualOrigin(std::shared_ptr<Pose> o);
  void setCollisionOrigin(std::shared_ptr<Pose> o);
  void clear() override;
  std::string toString() const override;
  bool empty() const override;
  const char* getTypename() const override;
  void setName(const std::string& name);
  std::string getName() const;
  void setInertia(const std::shared_ptr<Inertia> i);
  std::shared_ptr<Inertia> getInertia() const;
  void setVisual(const std::shared_ptr<Visual> v);
  std::shared_ptr<Visual> getVisual() const;
  void setMaterial(const std::shared_ptr<Material> m);
  std::shared_ptr<Material> getMaterial() const;
  void setCollision(const std::shared_ptr<Collision> c);
  void setCollisionGeometry(const std::shared_ptr<GeometryBase> g);
  void setVisualGeometry(const std::shared_ptr<GeometryBase> g);
  std::shared_ptr<Collision> getCollision() const;
  ~Link();

 private:
  std::string name;
  std::shared_ptr<Inertia> inertial;
  std::shared_ptr<Visual> visual;
  std::shared_ptr<Collision> collision;
  std::shared_ptr<Material> material;
};
#endif  // TINYURDF_LINK_H