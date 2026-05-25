#include "core/transmission.h"
#include <sstream>
#include <loguru/loguru.hpp>

Transmission::~Transmission() = default;

Transmission::Transmission() {
    name  = std::string();
    joint_name = std::string();
    actuator_name = std::string();
}

void Transmission::clear() {
    name = std::string();
    joint_name = std::string();
    actuator_name = std::string();
}

std::string Transmission::toString() const { 
    std::ostringstream os;
    os << "transmission name = " << this->name
       << ", joint name = " << this->joint_name
       << ", actuator name = " << this->actuator_name;
    return os.str();
 }

bool Transmission::isA(const char* name) const { 
    return std::string(name) == "transmission"; 
}

bool Transmission::empty() const { 
    return name.empty() && joint_name.empty() && actuator_name.empty();
}

const char* Transmission::getTypename() const { 
    return "transmission"; 
}

std::string Transmission::getJointName() { 
    return joint_name; 
}

std::string Transmission::getActuatorName() { 
    return actuator_name; 
}

std::string Transmission::getName() {
     return name; }
