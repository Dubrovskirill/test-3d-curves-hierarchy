#pragma once
#include "ICurve.h"


class Circle : public ICurve
{
    Circle(uint64_t id, const std::string& name, Point3D center, double radius);

    Point3D getPoint(double t) const override;
    Vector3D getDerivative(double t) const override;

    double getRadius() const { return m_radius; }

private:
    Point3D m_center;
    double m_radius;

};

