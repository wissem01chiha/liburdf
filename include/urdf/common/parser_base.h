#ifndef INCLUDE_URDF_COMMON_PARSER_BASE_H_
#define INCLUDE_URDF_COMMON_PARSER_BASE_H_

// Copyright 2024-2026 Wissem CHIHA

#include <tinyxml2/tinyxml2.h>
#include <memory>

#include "common/object_base.h"

template <class T>
class ParserBase : public ObjectBase
{
 public:
  const char* getNameOf(const tinyxml2::XMLElement* xml)
  {
    const char* name = xml->Attribute("name");
    if (!name)
    {
      return "";
    }
    else
    {
      return name;
    }
  }
  virtual int parse(const tinyxml2::XMLElement* xml) = 0;
  virtual std::shared_ptr<T> get() { return Tptr; }

 protected:
  ParserBase() {}
  virtual ~ParserBase() {}
  std::shared_ptr<T> Tptr;
};
#endif  // INCLUDE_URDF_COMMON_PARSER_BASE_H_