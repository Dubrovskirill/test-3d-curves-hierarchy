#include "Helix.h"
#include <cmath>
#include <stdexcept>

const double PI = std::acos(-1.0);

Helix::Helix(uint64_t id, const std::string& name, Point3D center, double radius, double step)
    : ICurve(id, name), m_center(center), m_radius(radius), m_step(step)
{
    if (m_radius <= 0) {
        throw std::invalid_argument("Helix radius must be positive!");
    }
}

Point3D Helix::getPoint(double t) const {
    return Point3D(
        m_center.x + m_radius * std::cos(t),
        m_center.y + m_radius * std::sin(t),
        m_center.z + (m_step * t) / (2.0 * PI)
    );
}

Vector3D Helix::getDerivative(double t) const {
    return Vector3D(
        -m_radius * std::sin(t),
        m_radius * std::cos(t),
        m_step / (2.0 * PI)
    );
}