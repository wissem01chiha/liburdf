#ifndef INCLUDE_URDF_INTERNAL_URDF_PARSER_H_
#define INCLUDE_URDF_INTERNAL_URDF_PARSER_H_

// Copyright 2024-2026 Wissem CHIHA

#include "common/parser_base.h"
#include "core/model.h"

/**
 * @brief Main user high-level interface for parsing URDF files.
 * @note This interface will be exposed to other languages or
 * external scripts.
 */
class URDFParser final : public ParserBase<Model>
{
 public:
  URDFParser();
  int parse(const std::string& filename);
  int parse(const char* filename);
  int parse(const tinyxml2::XMLElement* xml) override;
  std::shared_ptr<Model> get() override;
  std::string toString() const override;
  bool isA(const char* name) const override;
  bool empty() const override;
  void clear() override;
  const char* getTypename() const override;
  ~URDFParser();

 private:
  std::shared_ptr<Model> model_;
};
#endif  // INCLUDE_URDF_INTERNAL_URDF_PARSER_H_