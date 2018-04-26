#include <pybind11/embed.h>
#include <iostream>

namespace py = pybind11;

void call_python_interpreter()
{
  py::scoped_interpreter guard{};

  // py::exec("import os"); // OK
  // py::exec("import six"); // OK
  // py::exec("import sys"); // OK

  py::exec("import numpy"); // NOK
  // py::exec("import scipy"); // NOK
  // py::exec("import matplotlib"); // NOK
  // py::exec("import cv2"); // NOK
}

int main()
{
  call_python_interpreter();
  std::cout << "Call 1 OK\n"; 
  call_python_interpreter();
  std::cout << "Call 2 OK\n"; 
}

