#include "Circle.h"
#include <cmath>
#include <stdexcept>

Circle::Circle(uint64_t id, const std::string& name, Point3D center, double radius)
    : ICurve(id, name), m_center(center), m_radius(radius)
{
    if (m_radius <= 0) {
        throw std::invalid_argument("Radius must be positive!");
    }
}

Point3D Circle::getPoint(double t) const {
    return Point3D(
        m_center.x + m_radius * std::cos(t),
        m_center.y + m_radius * std::sin(t),
        m_center.z
    );
}

Vector3D Circle::getDerivative(double t) const {
    return Vector3D(
        -m_radius * std::sin(t),
        m_radius * std::cos(t),
        0.0
    );
}
