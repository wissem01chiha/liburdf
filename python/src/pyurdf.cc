#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(pyurdf, m) {
  m.doc() = "Python bindings for liburdf";
  py::module_ parser = py::module_::import("pyurdf_parser");
  m.attr("pyurdf_parser") = parser;
  m.attr("URDFParser") = parser.attr("URDFParser");
  m.attr("Model") = parser.attr("Model");
  m.attr("Link") = parser.attr("Link");
  m.attr("Joint") = parser.attr("Joint");
  m.attr("JointType") = parser.attr("JointType");
}