#include "internal/link_parser.h"

#include <loguru/loguru.hpp>

LinkParser::LinkParser() { p_ = std::make_shared<Link>(); }

int LinkParser::parse(const tinyxml2::XMLElement* xml) {
  if (xml == nullptr) {
    LOG_F(ERROR, "LinkParser::parse() received null pointer");
    return -1;
  }
  const char* link_name = ParserBase::getNameOf(xml);
  p_->setName(std::string(link_name));
  const tinyxml2::XMLElement* inertia_xml = xml->FirstChildElement("inertial");
  if (inertia_xml) {
    InertiaParser ip;
    int ips = ip.parse(inertia_xml);
    if (ips) return ips;
    const auto id = ip.get();
    p_->setInertia(id);
  }

  const tinyxml2::XMLElement* collision_xml = xml->FirstChildElement("collision");
  bool first_collision = true;
  while (collision_xml) {
    CollisionParser coop;
    int cps = coop.parse(collision_xml);
    if (cps) return cps;
    const auto co_ptr = coop.get();
    if (first_collision) {
      p_->setCollision(co_ptr);
      first_collision = false;
    } else {
      p_->addCollision(co_ptr);
    }
    collision_xml = collision_xml->NextSiblingElement("collision");
  }
  const tinyxml2::XMLElement* visual_xml = xml->FirstChildElement("visual");
  bool first_visual = true;
  while (visual_xml) {
    VisualParser vp;
    int vps = vp.parse(visual_xml);
    if (vps) return vps;
    const auto vi_ptr = vp.get();
    if (first_visual) {
      p_->setVisual(vi_ptr);
      first_visual = false;
    } else {
      p_->addVisual(vi_ptr);
    }
    visual_xml = visual_xml->NextSiblingElement("visual");
  }
  return 0;
}

bool LinkParser::isA(const char* name) const {
  return p_ ? p_->isA(name) : false;
}

bool LinkParser::empty() const { return p_ ? p_->empty() : true; }

void LinkParser::clear() {
  if (p_) {
    p_->clear();
  }
}

std::string LinkParser::toString() const {
  std::ostringstream os;
  os << "Parsed Link = [";
  os << p_->toString();
  os << "]\n";
  return os.str();
}

const char* LinkParser::getTypename() const {
  return p_ ? p_->getTypename() : "unknown";
}

std::shared_ptr<Link> LinkParser::get() { return p_; }
