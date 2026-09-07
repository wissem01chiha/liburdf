#ifndef INCLUDE_URDF_INTERNAL_BOX_SERIALIZER_H_
#define INCLUDE_URDF_INTERNAL_BOX_SERIALIZER_H_

// Copyright 2024-2026 Wissem CHIHA

#include "common/serializer_base.h"
#include "core/box.h"

/**
 * @brief Serializer for Box geometry
 */
class BoxSerializer : public SerializerBase<Box, tinyxml2::XMLElement> {
 public:
  BoxSerializer();
  int serialize(const Box* box) override;
  std::shared_ptr<tinyxml2::XMLElement> get() override;
  ~BoxSerializer() override;

 private:
  std::shared_ptr<tinyxml2::XMLElement> p_;
};

#endif  // INCLUDE_URDF_INTERNAL_BOX_SERIALIZER_H_