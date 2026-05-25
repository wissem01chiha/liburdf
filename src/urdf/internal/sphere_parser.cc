#include "internal/sphere_parser.h"
#include "utility/string_utils.h"
#include <loguru/loguru.hpp>

SphereParser::SphereParser() {
  p_ = std::make_shared<Sphere>();
}

int SphereParser::parse(const tinyxml2::XMLElement* xml) {
    if (xml == nullptr)
      {
        LOG_F(ERROR, "SphereParser::parse() received null pointer");
        return -1;
      }

  const char* radius_str = xml->Attribute("radius");
  if (radius_str) {
    double r;
    str2double(radius_str, r);
    p_ = std::make_shared<Sphere>();
    p_->setRadius(r);
  }
  return 0;
}

bool SphereParser::isA(const char* name) const {
  return p_->isA(name);
}

const char* SphereParser::getTypename()  const {
  return p_->getTypename();
}

std::string SphereParser::toString() const {

  std::ostringstream os;
  os << "Parsed Sphere = [";
  os << p_->toString();
  os << "]";
  return os.str();
  
}

bool SphereParser::empty() const {
  return p_ == nullptr;
}

void SphereParser::clear() {
  p_->clear();
}

std::shared_ptr<Sphere> SphereParser::get() {
  return p_;
}
