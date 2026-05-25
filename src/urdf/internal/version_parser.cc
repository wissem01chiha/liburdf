#include "internal/version_parser.h"
#include <loguru/loguru.hpp>

VersionParser::VersionParser(){
    p_ = std::make_shared<Version>();
};

int VersionParser::parse(tinyxml2::XMLDocument doc)
{
    if(doc.NoChildren())
    {
        LOG_F(ERROR, "VersionParser::parse() received empty XML document");
        return -1;
    }
    tinyxml2::XMLDeclaration* decl = doc.FirstChild()->ToDeclaration();
    if (decl) 
    {
        const char* version_str = decl->Value();
        const char *versionStart = strstr(version_str, "version=\"");
        
        versionStart += 9; 
        char version_[20]; 
        #ifdef _MSC_VER
            sscanf_s(versionStart, "%19[^\"]", version_, (unsigned)_countof(version_));
        #else 
            sscanf(versionStart, "%19[^\"]", version_); 
        #endif
        const char* constVersion = version_;
        LOG_F(INFO, "XML Version detected: %s", constVersion);
        Version version(constVersion);
        p_ = std::make_shared<Version>(version);
        if (!version.equal(static_cast<double>(1), static_cast<double>(0)))
        {
            LOG_F(ERROR, "Parser Engine : only XML version 1.0 supported");
        }else {
            LOG_F(ERROR,"No XML declaration found!");
        }
    }
}

const char *VersionParser::getTypename() const
{
    return "version";
}
VersionParser::~VersionParser(){
    p_.reset();
};