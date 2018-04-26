#include <pybind11/embed.h>
#include <iostream>

namespace py = pybind11;

__declspec(dllexport) void call_python_interpreter_import_numpy_twice()
{
  {
    py::scoped_interpreter guard{};
    py::exec("import numpy");
  }
  {
    py::scoped_interpreter guard{};
    py::exec("import numpy");
  }
}
