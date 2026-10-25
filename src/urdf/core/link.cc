#include "core/link.h"

#include <loguru/loguru.hpp>

Link::Link() { this->name = std::string("Link"); }

bool Link::isA(const char* name) const { return std::string(name) == "Link"; }

void Link::clear() {
  this->name.clear();
  this->inertial.reset();
  this->visuals.clear();
  this->collisions.clear();
  this->material.reset();
}

std::string Link::toString() const {
  std::ostringstream os;
  os << "Link : [" << name.c_str();
  for (const auto& visual : visuals) {
    os << ", " << visual->toString();
  }
  if (inertial) {
    os << ", ";
    os << inertial->toString();
  }
  for (const auto& collision : collisions) {
    os << ", " << collision->toString();
  }
  os << "]";
  return os.str();
}

bool Link::empty() const { return false; }

const char* Link::getTypename() const { return "link"; }

void Link::setName(const std::string& name) {
  if (!name.empty()) {
    this->name = name;
  }
}

std::string Link::getName() const { return name; }

void Link::setInertia(const std::shared_ptr<Inertia> i) {
  if (i) {
    inertial = i;
  }
}

std::shared_ptr<Inertia> Link::getInertia() const { return inertial; }

void Link::setVisual(const std::shared_ptr<Visual> v) {
  if (v) {
    if (visuals.empty()) {
      visuals.push_back(v);
    } else {
      visuals.front() = v;
    }
  }
}

std::shared_ptr<Visual> Link::getVisual() const {
  return visuals.empty() ? nullptr : visuals.front();
}

void Link::addVisual(const std::shared_ptr<Visual> v) {
  if (v) {
    visuals.push_back(v);
  }
}

std::vector<std::shared_ptr<Visual>> Link::getVisuals() const {
  return visuals;
}

void Link::setMaterial(const std::shared_ptr<Material> m) {
  if (m) {
    material = m;
  }
}

std::shared_ptr<Material> Link::getMaterial() const { return material; }

void Link::setCollision(const std::shared_ptr<Collision> c) {
  if (c) {
    if (collisions.empty()) {
      collisions.push_back(c);
    } else {
      collisions.front() = c;
    }
  }
}

void Link::addCollision(const std::shared_ptr<Collision> c) {
  if (c) {
    collisions.push_back(c);
  }
}

std::vector<std::shared_ptr<Collision>> Link::getCollisions() const {
  return collisions;
}

void Link::setCollisionGeometry(const std::shared_ptr<GeometryBase> g) {
  if (g) {
    if (collisions.empty()) {
      addCollision(std::make_shared<Collision>());
    }
    collisions.front()->setGeometry(g);
  }
}

void Link::setVisualGeometry(const std::shared_ptr<GeometryBase> g) {
  if (g) {
    if (visuals.empty()) {
      addVisual(std::make_shared<Visual>());
    }
    visuals.front()->setGeometry(g);
  }
}

std::shared_ptr<Collision> Link::getCollision() const {
  return collisions.empty() ? nullptr : collisions.front();
}

Link::~Link() {}

void Link::getOrigin(double* pos) const {
  if (!visuals.empty()) {
    visuals.front()->getOrigin(pos);
  }
}

void Link::setVisualOrigin(std::shared_ptr<Pose> o) {
  if (o) {
    if (visuals.empty()) {
      addVisual(std::make_shared<Visual>());
    }
    visuals.front()->setOrigin(o);
  }
}

void Link::setCollisionOrigin(std::shared_ptr<Pose> o) {
  if (o) {
    if (collisions.empty()) {
      addCollision(std::make_shared<Collision>());
    }
    collisions.front()->setOrigin(o);
  }
};
