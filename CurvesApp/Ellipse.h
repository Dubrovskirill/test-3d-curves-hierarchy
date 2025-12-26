#pragma once
#include "ICurve.h"
class Ellipse : public ICurve
{
    Ellipse(uint64_t id, const std::string& name, Point3D center, double radiusX, double radiusY);

    Point3D getPoint(double t) const override;
    Vector3D getDerivative(double t) const override;

    double getRadiusX() const { return m_radiusX; }
    double getRadiusY() const { return m_radiusY; }

private:
    Point3D m_center;
    double m_radiusX;
    double m_radiusY;
};

