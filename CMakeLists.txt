cmake_minimum_required(VERSION 3.16)
project(cpp_function)
set(CMAKE_CXX_STANDARD 17)
set(SOURCE "${PROJECT_SOURCE_DIR}")
set(THIRDPARTYLIB "${PROJECT_SOURCE_DIR}/ThirdPartyLib")

# pybind11
add_subdirectory(${THIRDPARTYLIB}/pybind11)

# module
pybind11_add_module (
    cpp_function
    ${SOURCE}/main.cpp
)
