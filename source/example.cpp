#include <pybind11/pybind11.h>

float AddCpp(float mass, float angle, float velocity, float drag)
{
    return mass + angle + velocity + drag;
}

PYBIND11_MODULE(example, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring
    m.def("add", &AddCpp, "A function that adds two numbers");
}