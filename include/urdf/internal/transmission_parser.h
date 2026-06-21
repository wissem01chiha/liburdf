#ifndef INCLUDE_URDF_INTERNAL_SPHERE_PARSER_H_
#define INCLUDE_URDF_INTERNAL_SPHERE_PARSER_H_

// Copyright 2024-2026 Wissem CHIHA

#include <core/transmission.h>

#include "common/parser_base.h"

class TransmissionParser : public ParserBase<Transmission> {
 public:
  TransmissionParser();

 private:
  std::shared_ptr<Transmission> p_;
};

#endif  // INCLUDE_URDF_INTERNAL_SPHERE_PARSER_H_
