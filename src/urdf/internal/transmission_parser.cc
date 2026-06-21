#include "internal/transmission_parser.h"

#include <loguru/loguru.hpp>

#include "utility/string_utils.h"

TransmissionParser::TransmissionParser() {
  p_ = std::make_shared<Transmission>();
}
