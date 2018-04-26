cmake_minimum_required(VERSION 2.8.12)
project(test_np_pybind)

add_subdirectory(pybind11)
pybind11_add_module(lib SHARED lib.cpp)
add_executable(main main.cpp)
target_link_libraries(main PRIVATE lib)

