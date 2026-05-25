#include "internal/cylinder_parser.h"
#include "utility/string_utils.h"
#include <loguru/loguru.hpp>

CylinderParser::CylinderParser() {
  p_ = std::make_shared<Cylinder>();
}

int CylinderParser::parse(const tinyxml2::XMLElement* xml) {
  
  if(xml == nullptr)
  {
    LOG_F(ERROR, "CylinderParser::parse() received null pointer");
    return -1;
  }

  const char* radius_str = xml->Attribute("radius");
  const char* length_str = xml->Attribute("length");
  if (radius_str && length_str) {
    double r, l;
    str2double(radius_str, r);
    str2double(length_str, l);
    p_ = std::make_shared<Cylinder>();
    p_->setRadius(r);
    p_->setLength(l);
  }
  return 0;
}

bool CylinderParser::isA(const char* name) const {
  return p_->isA(name);
}

const char* CylinderParser::getTypename() const {
  return p_->getTypename();
}

std::string CylinderParser::toString() const {
  std::ostringstream os;
  os << "Parsed Cylinder = [";
  os << p_->toString();
  os << "]";
  return os.str();
}

bool CylinderParser::empty() const {
  return p_ == nullptr;
}

void CylinderParser::clear() {
  p_->clear();
}

std::shared_ptr<Cylinder> CylinderParser::get() {
  return p_;
}