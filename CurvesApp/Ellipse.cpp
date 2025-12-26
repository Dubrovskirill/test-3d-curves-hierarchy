#include "Ellipse.h"
#include <cmath>
#include <stdexcept>

Ellipse::Ellipse(uint64_t id, const std::string& name, Point3D center, double radiusX, double radiusY)
    : ICurve(id, name), m_center(center), m_radiusMinor(radiusX), m_radiusMajor(radiusY)
{
    if (m_radiusMinor <= 0 || m_radiusMajor <= 0) {
        throw std::invalid_argument("Ellipse radii must be positive!");
    }
}

Point3D Ellipse::getPoint(double t) const {
    return Point3D(
        m_center.x + m_radiusMinor * std::cos(t),
        m_center.y + m_radiusMajor * std::sin(t),
        m_center.z
    );
}

Vector3D Ellipse::getDerivative(double t) const {
    return Vector3D(
        -m_radiusMinor * std::sin(t),
        m_radiusMajor * std::cos(t),
        0.0
    );
}