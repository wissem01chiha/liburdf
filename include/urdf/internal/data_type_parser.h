#ifndef URDF_INTERNAL_DATA_TYPE_PARSER_H
#define URDF_INTERNAL_DATA_TYPE_PARSER_H

#include <core/data_type.h>

#include "common/parser_base.h"

/**
 * \brief A parser for the DataType class.
 * \note This is a placeholder parser for the DataType class
 */
class DataTypeParser : public ParserBase<DataType> {
 public:
  DataTypeParser();
  int parse(const tinyxml2::XMLElement* xml) override;
  std::shared_ptr<DataType> get() override;
  const char* getTypename() const override;
  bool isA(const char* name) const override;
  bool empty() const override;
  void clear() override;
  std::string toString() const override;

 private:
  std::shared_ptr<DataType> p_;
};

#endif  // URDF_INTERNAL_DATA_TYPE_PARSER_H
