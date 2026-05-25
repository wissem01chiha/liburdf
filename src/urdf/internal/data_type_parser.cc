#include "internal/data_type_parser.h"
#include "utility/string_utils.h"
#include <loguru/loguru.hpp>

DataTypeParser::DataTypeParser() { 
  p_ = std::make_shared<DataType>();
}

int DataTypeParser::parse(const tinyxml2::XMLElement* xml) { return 0; }

const char* DataTypeParser::getTypename() const { return "data_type"; }

bool DataTypeParser::isA(const char* name) const { return std::strcmp(name, "data_type") == 0; }

bool DataTypeParser::empty() const { return !p_; }

void DataTypeParser::clear() {
  p_->clear();
  p_ = nullptr;
}

std::string DataTypeParser::toString() const { return p_->toString(); }

std::shared_ptr<DataType> DataTypeParser::get()
{
  return p_;
}