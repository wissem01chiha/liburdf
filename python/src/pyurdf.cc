#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(pyurdf, m) {
  m.doc() = "Python bindings for liburdf";
  // init_pyurdf_parser(m);
}