#ifndef LIBURDF_PYTHON_SRC_PYURDF_BINDINGS_H_
#define LIBURDF_PYTHON_SRC_PYURDF_BINDINGS_H_

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "../../include/urdf.h"

// Copyright 2024-2026 Wissem CHIHA

namespace py = pybind11;

inline void init_link(py::module& m) {
  py::class_<Link, std::shared_ptr<Link>>(m, "Link")
      .def(py::init<>())
      .def("clear", &Link::clear)
      .def("setName", &Link::setName)
      .def("getName", &Link::getName)
      .def("isA", &Link::isA)
      .def("getTypename", &Link::getTypename)
      .def("empty", &Link::empty)
      .def("getInertia", &Link::getInertia)
      .def("getVisual", &Link::getVisual)
      .def("getCollision", &Link::getCollision);
}

inline void init_joint(py::module& m) {
  py::enum_<Joint::Type>(m, "JointType")
      .value("UNKNOWN", Joint::Type::UNKNOWN)
      .value("REVOLUTE", Joint::Type::REVOLUTE)
      .value("CONTINUOUS", Joint::Type::CONTINUOUS)
      .value("PRISMATIC", Joint::Type::PRISMATIC)
      .value("FLOATING", Joint::Type::FLOATING)
      .value("PLANAR", Joint::Type::PLANAR)
      .value("FIXED", Joint::Type::FIXED)
      .value("UNIVERSAL", Joint::Type::UNIVERSAL)
      .export_values();

  py::class_<Joint, std::shared_ptr<Joint>>(m, "Joint")
      .def(py::init<>())
      .def("clear", &Joint::clear)
      .def("setName", &Joint::setName)
      .def("getName", &Joint::getName)
      .def("setType", py::overload_cast<const Joint::Type&>(&Joint::setType))
      .def("setType", py::overload_cast<const char*>(&Joint::setType))
      .def("getType", &Joint::getType)
      .def("setAxis", &Joint::setAxis)
      .def("pushBackChild", &Joint::pushBackChild)
      .def("pushBackParent", &Joint::pushBackParent)
      .def("isChild", &Joint::isChild)
      .def("isParent", &Joint::isParent)
      .def("getChild", &Joint::getChild)
      .def("getParent", &Joint::getParent)
      .def("isA", &Joint::isA)
      .def("getTypename", &Joint::getTypename)
      .def("empty", &Joint::empty);
}

inline void init_model(py::module& m) {
  py::class_<Model, std::shared_ptr<Model>>(m, "Model")
      .def(py::init<>())
      .def("clear", &Model::clear)
      .def("setName", &Model::setName)
      .def("getName", &Model::getName)
      .def("isA", &Model::isA)
      .def("getTypename", &Model::getTypename)
      .def("empty", &Model::empty)
      .def("setLink",
           static_cast<void (Model::*)(std::shared_ptr<Link>)>(&Model::setLink))
      .def("setLink",
           static_cast<void (Model::*)(std::vector<std::shared_ptr<Link>>)>(
               &Model::setLink))
      .def("setJoint", static_cast<void (Model::*)(std::shared_ptr<Joint>)>(
                           &Model::setJoint))
      .def("setJoint",
           static_cast<void (Model::*)(std::shared_ptr<Joint>,
                                       const std::string&, const std::string&)>(
               &Model::setJoint))
      .def("setJoint",
           static_cast<void (Model::*)(std::vector<std::shared_ptr<Joint>>)>(
               &Model::setJoint))
      .def("getJoints", &Model::getJoints)
      .def("getLinks", &Model::getLinks);
}

inline void init_pyurdf_parser(py::module& m) {
  py::class_<URDFParser, std::shared_ptr<URDFParser>>(m, "URDFParser")
      .def(py::init<>())
      .def("get", &URDFParser::get)
      .def("parse",
           static_cast<int (URDFParser::*)(const std::string&)>(
               &URDFParser::parse),
           "Parse URDF from filename")
      .def("parse",
           static_cast<int (URDFParser::*)(const char*)>(&URDFParser::parse),
           "Parse URDF from C-string filename")
      .def("clear", &URDFParser::clear, "Clears the parser's state")
      .def("isA", &URDFParser::isA, "Check the type of the parser")
      .def("empty", &URDFParser::empty, "Check if the parser is empty")
      .def("getTypename", &URDFParser::getTypename,
           "Get the type name of the parser");
}

inline void init_bindings(py::module& m) {
  init_link(m);
  init_joint(m);
  init_model(m);
  init_pyurdf_parser(m);
}

#endif  // LIBURDF_PYTHON_SRC_PYURDF_BINDINGS_H_