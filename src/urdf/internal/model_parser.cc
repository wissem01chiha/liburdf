#include "internal/model_parser.h"

#include <cstring>

#include <loguru/loguru.hpp>

ModelParser::ModelParser() { p_ = std::make_shared<Model>(); }

int ModelParser::parse(const tinyxml2::XMLElement* xml) {
  if (xml == nullptr) {
    LOG_F(ERROR, "ModelParser::parse() received null pointer");
    return -1;
  }

  const tinyxml2::XMLElement* model_name_xml =
      std::strcmp(xml->Name(), "robot") == 0 ? xml
                                               : xml->FirstChildElement("robot");
  if (model_name_xml == nullptr) {
    LOG_F(ERROR, "ModelParser::parse() failed to find 'robot' element");
    return -1;
  }
  const char* model_name = model_name_xml->Attribute("name");
  if (model_name == nullptr) {
    LOG_F(ERROR, "ModelParser::parse() failed to find 'name' attribute in 'robot' element");
    return -1;
  }
  p_->setName(model_name);

  int result = parseLinks(xml);
  if (result != 0) {
    return result;
  }

  result = parseJoints(xml);
  if (result != 0) {
    return result;
  }

  LOG_F(INFO, "Model parsed successfully");
  return 0;
}

int ModelParser::parseLinks(const tinyxml2::XMLElement* xml) {
  LOG_F(INFO, "Parsing Model links ...");
  const tinyxml2::XMLElement* link_xml = xml->FirstChildElement("link");
  while (link_xml != nullptr) {
    LinkParser parser;
    const int result = parser.parse(link_xml);
    if (result != 0) {
      return result;
    }
    p_->setLink(parser.get());
    link_xml = link_xml->NextSiblingElement("link");
  }

  return 0;
}

int ModelParser::parseJoints(const tinyxml2::XMLElement* xml) {
  LOG_F(INFO, "Parsing Model joints ...");
  const tinyxml2::XMLElement* joint_xml = xml->FirstChildElement("joint");
  while (joint_xml != nullptr) {
    JointParser parser;
    const int result = parser.parse(joint_xml);
    if (result != 0) {
      return result;
    }
    p_->setJoint(parser.get());
    joint_xml = joint_xml->NextSiblingElement("joint");
  }

  return 0;
}

std::shared_ptr<Model> ModelParser::get() { return p_; }

std::string ModelParser::toString() const {
  std::ostringstream os;
  os << "Parsed Model :[";
  os << p_->toString();
  os << "]\n";
  return os.str();
}

bool ModelParser::isA(const char* name) const { return p_->isA(name); }

bool ModelParser::empty() const { return p_->empty(); }

void ModelParser::clear() { p_->clear(); }

const char* ModelParser::getTypename() const { return p_->getTypename(); };
