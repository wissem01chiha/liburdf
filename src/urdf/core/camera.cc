#include "core/camera.h"

Camera::Camera() {
  origin = std::make_shared<Pose>();
  mat = std::make_shared<Image<double, 4>>();
  update_rate = 1.0;
  hfov = 1.0;
  near = 1.0;
  far = 1.0;
  type = Type::B8G8R8;
}

Camera::Camera(const Camera &rhs) {
  origin = std::make_shared<Pose>(*rhs.origin);
  mat = std::make_shared<Image<double, 4>>(*rhs.mat);
  update_rate = rhs.update_rate;
  hfov = rhs.hfov;
  near = rhs.near;
  far = rhs.far;
  type = rhs.type;
}

void Camera::reset() {
  type = Type::B8G8R8;
  update_rate = 1.0;
  hfov = 1.0;
  near = 1.0;
  far = 1.0;
  origin = std::make_shared<Pose>();
  mat = std::make_shared<Image<double, 4>>();
}

void Camera::getOrigin(double *xyz) const {
  const auto vec = origin->getPosition();
  for (size_t i = 0; i < 3; i++) {
    xyz[i] = vec[i];
  }
}

void Camera::setType(Type t_) { type = t_; }

void Camera::setType(const char *c) {
  if (!c) return;
  std::string typeStr(c);
  if (typeStr == "L8")
    type = Type::L8;
  else if (typeStr == "R8G8B8")
    type = Type::R8G8B8;
  else if (typeStr == "B8G8R8")
    type = Type::B8G8R8;
  else if (typeStr == "BAYER_RGGB8")
    type = Type::BAYER_RGGB8;
  else if (typeStr == "BAYER_BGGR8")
    type = Type::BAYER_BGGR8;
  else if (typeStr == "BAYER_GBRG8")
    type = Type::BAYER_GBRG8;
  else if (typeStr == "BAYER_GRBG8")
    type = Type::BAYER_GRBG8;
}

void Camera::setHfov(double hfov_) {
  if (hfov_ > 0) {
    hfov = hfov_;
  }
}
void Camera::setNear(double near_) {
  if (near_ > 0) {
    near = near_;
  }
}

void Camera::setFar(double far_) {
  if (far_ > 0) {
    far = far_;
  }
}
void Camera::setUpdateRate(double ur) {
  if (ur > 0) {
    update_rate = ur;
  }
}

double Camera::getUpdateRate() const { return update_rate; }

void Camera::setOrigin(std::shared_ptr<Pose> o) {
  if (o) {
    origin = o;
  }
}

const char *Camera::getTypename() const { return "camera"; }

bool Camera::empty() const {
  if (!mat) {
    return true;
  }
  if (mat->width() == 0 || mat->height() == 0) {
    return true;
  }
  return false;
}

bool Camera::isA(const char *name) const {
  return std::strcmp(name, "camera") == 0;
}

void Camera::clear() {
  mat.reset();
  origin.reset();
  hfov = 0.0;
  near = 0.0;
  far = 0.0;
  update_rate = 0.0;
  type = Camera::Type::B8G8R8;
}

void Camera::getRange(Image<double, 4> &r) { r = *mat; }

void Camera::setRange(Image<double, 4> &r) { *mat = r; }

Camera::Type Camera::getType() const { return type; }

double Camera::getHfov() const { return hfov; }

double Camera::getNear() const { return near; }

double Camera::getFar() const { return far; }

void Camera::get(Image<double, 4> &o) const { o = *mat; }

void Camera::set(const std::shared_ptr<Image<double, 4>> mat_) {
  if (mat_) {
    mat = mat_;
  }
}

std::string Camera::toString() const {
  std::ostringstream os;
  os << "Camera : "
     << " [Type: " << static_cast<int>(type) << ", " << origin->toString()
     << ", hfov = " << hfov << ", far = " << far << ", near = " << near
     << ", update_rate = " << update_rate << "]\n";
  return os.str();
}

void Camera::update() {}