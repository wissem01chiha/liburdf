#include "internal/urdf_parser.h"
#include "internal/model_parser.h"
#include "internal/pose_parser.h"
#include "internal/version_parser.h"
#include "utility/string_utils.h"
#include <loguru/loguru.hpp>

URDFParser::URDFParser()
{
    this->model_ = std::make_shared<Model>();
}

int URDFParser::parse(const tinyxml2::XMLElement *xml)
{
    if(xml == nullptr)
    {
        LOG_F(ERROR, "URDFParser::parse() received null pointer");
        return -1;
    }   
    ModelParser mp;
    int result = mp.parse(xml);
    if (result != 0) {
        return result;
    }
    this->model_ = mp.get();
}

int URDFParser::parse(const char *filename)
{
    if(filename == nullptr)
    {
        LOG_F(ERROR, "URDFParser::parse() received null pointer");
        return -1;
    }
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLError eResult = doc.LoadFile(filename);
    if (eResult != tinyxml2::XML_SUCCESS) {
        LOG_F(ERROR, "Error loading XML file: %s" , doc.ErrorStr());
        return -1;
    }
    else {
        const tinyxml2::XMLElement *xml = doc.FirstChildElement("robot");
        if(!xml) {
            LOG_F(ERROR, "Error: This is not a valid URDF file format");
            return -1;
        }
        VersionParser vp;
        vp.parse(&doc);
        this->parse(xml);
    }
    return 0;
}

int URDFParser::parse(const std::string &filename)
{
    return this->parse(filename.c_str());
}

std::shared_ptr<Model> URDFParser::get()
{
    return this->model_;
}

std::string URDFParser::toString() const
{
    std::ostringstream os;
    os << this->model_->toString();
    return os.str();
}

bool URDFParser::isA(const char *name) const 
{
    return this->model_->isA(name);
}

bool URDFParser::empty() const
{
    return this->model_->empty();
}

void URDFParser::clear()
{
    this->model_->clear();
}

const char *URDFParser::getTypename() const
{
    return this->model_->getTypename();
}

URDFParser::~URDFParser(){}