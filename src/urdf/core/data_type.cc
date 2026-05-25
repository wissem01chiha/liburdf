#include "core/data_type.h"

DataType::DataType() {}

std::string DataType::toString() const { return std::string(); }

bool DataType::isA(const char* name) const { return false; }

void DataType::clear() {}