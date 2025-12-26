#include "Ellipse.h"
#include <cmath>
#include <stdexcept>

Ellipse::Ellipse(uint64_t id, const std::string& name, Point3D center, double radiusX, double radiusY)
    : ICurve(id, name), m_center(center), m_radiusX(radiusX), m_radiusY(radiusY)
{
    if (m_radiusX <= 0 || m_radiusY <= 0) {
        throw std::invalid_argument("Ellipse radii must be positive!");
    }
}

Point3D Ellipse::getPoint(double t) const {
    return Point3D(
        m_center.x + m_radiusX * std::cos(t),
        m_center.y + m_radiusY * std::sin(t),
        m_center.z
    );
}

Vector3D Ellipse::getDerivative(double t) const {
    return Vector3D(
        -m_radiusX * std::sin(t),
        m_radiusY * std::cos(t),
        0.0
    );
}