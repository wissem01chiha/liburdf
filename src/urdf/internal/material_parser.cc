#include "internal/material_parser.h"

#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <loguru/loguru.hpp>
#include <sstream>

MaterialParser::MaterialParser() { this->p_ = std::make_shared<Material>(); }

std::string MaterialParser::toString() const {
  std::ostringstream os;
  os << "Parsed Material = [";
  os << p_->toString();
  os << "]";
  return os.str();
}

bool MaterialParser::empty() const { return false; }

void MaterialParser::clear() { p_->clear(); }

const char* MaterialParser::getTypename() const { return "material"; }

bool MaterialParser::isA(const char* name) const { return p_->isA(name); }

int MaterialParser::parse(const tinyxml2::XMLElement* xml) {
  if (xml == nullptr) {
    LOG_F(ERROR, "MaterialParser::parse() received null pointer");
    return -1;
  }
  const char* name_mat_str = xml->Attribute("name");
  if (name_mat_str) {
    p_->setName(std::string(name_mat_str));
  }

  const tinyxml2::XMLElement* density_xml = xml->FirstChildElement("density");
  if (density_xml != nullptr) {
    const char* density_value = density_xml->Attribute("value");
    if (density_value != nullptr) {
      char* end = nullptr;
      errno = 0;
      const double density = std::strtod(density_value, &end);
      if (end != density_value && *end == '\0' && errno != ERANGE &&
          std::isfinite(density)) {
        p_->setDensity(density);
      } else {
        LOG_F(WARNING, "Ignoring  material density: %s", density_value);
      }
    }
  }

  const tinyxml2::XMLElement* color_xml = xml->FirstChildElement("color");
  ColorParser cp;
  int cps = cp.parse(color_xml);
  if (cps) return cps;
  const auto cd = cp.get();
  double r, g, b, a;
  r = cd->getR();
  g = cd->getG();
  b = cd->getB();
  a = cd->getA();
  p_->setColor(r, g, b, a);

  const tinyxml2::XMLElement* txt_xml = xml->FirstChildElement("texture");
  if (txt_xml != nullptr) {
    PropertyParser<std::string> sp;
    int sps = sp.parse(txt_xml);
    if (sps) return sps;
    const auto dsp = sp.get();
    p_->setFilename((*dsp)["filename"]);
  }
  return 0;
}

std::shared_ptr<Material> MaterialParser::get() { return p_; }

MaterialParser::~MaterialParser() = default;
