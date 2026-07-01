#include "internal/visual_parser.h"

#include <loguru/loguru.hpp>

#include "utility/string_utils.h"

VisualParser::VisualParser() { this->p_ = std::make_shared<Visual>(); }

std::string VisualParser::toString() const {
  std::ostringstream os;
  os << "Parsed Visual = [";
  os << p_->toString();
  os << "]";
  return os.str();
}

bool VisualParser::empty() const { return this->p_->empty(); }

void VisualParser::clear() { p_->clear(); }

const char* VisualParser::getTypename() const {
  return this->p_->getTypename();
}

VisualParser::~VisualParser() {}

bool VisualParser::isA(const char* name) const { return p_->isA(name); }

int VisualParser::parse(const tinyxml2::XMLElement* xml) {
  if (xml == nullptr) {
    LOG_F(ERROR, "VisualParser::parse() received null pointer");
    return -1;
  }
  const tinyxml2::XMLElement* o_xml = xml->FirstChildElement("origin");
  if (o_xml) {
    PoseParser pp;
    int result = pp.parse(o_xml);
    if (result != 0) {
      return result;
    }
    const auto pp_ptr = pp.get();
    p_->setOrigin(pp_ptr);
  }
  const tinyxml2::XMLElement* geometry_xml = xml->FirstChildElement("geometry");

  if (geometry_xml) {
    GeometryParser gp;
    int result = gp.parse(geometry_xml);
    if (result != 0) {
      return result;
    }
    const auto gp_ptr = gp.get();
    p_->setGeometry(gp_ptr);
  }
  const tinyxml2::XMLElement* material_xml = xml->FirstChildElement("material");
  if (material_xml) {
    MaterialParser mp;
    int result = mp.parse(material_xml);
    if (result != 0) {
      return result;
    }
    const auto mp_ptr = mp.get();
    p_->setMaterial(mp_ptr);
  }
  return 0;
}

std::shared_ptr<Visual> VisualParser::get() { return p_; };
