#ifndef INCLUDE_URDF_INTERNAL_MESH_PARSER_H_
#define INCLUDE_URDF_INTERNAL_MESH_PARSER_H_

// Copyright 2024-2026 Wissem CHIHA

#include "common/geometry_base.h"
#include "common/parser_base.h"
#include "core/mesh.h"

/**
 * @brief Parser for Mesh geometry, inherits from ParserBase<Mesh>
 * and provides the functionality to parse the mesh geometry from XML.
 */
class MeshParser final : public ParserBase<Mesh>
{
 public:
  MeshParser();
  int parse(const tinyxml2::XMLElement* xml) override;
  bool isA(const char* name) const override;
  const char* getTypename() const override;
  std::string toString() const override;
  bool empty() const override;
  void clear() override;
  std::shared_ptr<Mesh> get() override;
  ~MeshParser() override;

 private:
  std::shared_ptr<Mesh> p_;
};
#endif  // INCLUDE_URDF_INTERNAL_MESH_PARSER_H_
