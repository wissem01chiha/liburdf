#include "internal/transmission_parser.h"
#include "utility/string_utils.h"
#include <loguru/loguru.hpp>

TransmissionParser::TransmissionParser() {
  p_ = std::make_shared<Transmission>();
}

