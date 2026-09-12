#include "../include/pyurdf_bindings.h"

PYBIND11_MODULE(pyurdf_parser, m) {
  m.doc() = "Python bindings for liburdf parser ";
  init_bindings(m);
}