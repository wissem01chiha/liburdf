#include "internal/version_parser.h"

#include <loguru/loguru.hpp>

#include "utility/string_utils.h"

VersionParser::VersionParser() { p_ = std::make_shared<Version>(); };

int VersionParser::parse(const tinyxml2::XMLDocument& doc) {
  if (doc.NoChildren()) {
    LOG_F(ERROR, "VersionParser::parse() received empty XML document");
    return -1;
  }
  const tinyxml2::XMLDeclaration* decl = doc.FirstChild()->ToDeclaration();
  if (!decl) {
    LOG_F(ERROR, "No XML declaration found!");
    return -1;
  }

  const char* version_str = decl->Value();
  if (!version_str) {
    LOG_F(ERROR, "No version string found in XML declaration!");
    return -1;
  }

  // support for both single and double quotes in the version attribute
  const char* versionStart = strstr(version_str, "version=\"");
  if (versionStart == NULL) {
    versionStart = strstr(version_str, "version='");
    if (versionStart == NULL) {
      LOG_F(ERROR, "No valid version attribute found in XML declaration!");
      return -1;
    }
  }

  versionStart += 9;
  char version_[20];
  sscanf_w(versionStart, "%19[^\"]", version_, (unsigned)sizeof(version_));
  const char* constVersion = version_;
  LOG_F(INFO, "XML Version detected: %s", constVersion);
  Version version(constVersion);
  p_ = std::make_shared<Version>(version);

  if (!version.equal(static_cast<double>(1), static_cast<double>(0))) {
    LOG_F(ERROR, "VersionParser : only XML version 1.0 supported");
    return -1;
  }

  return 0;
}

const char* VersionParser::getTypename() const { return "version"; }
VersionParser::~VersionParser() { p_.reset(); };