#pragma once
#include "ICurve.h"
class Helix : public ICurve
{

    Helix(uint64_t id, const std::string& name, Point3D center, double radius, double step);

    Point3D getPoint(double t) const override;
    Vector3D getDerivative(double t) const override;


    double getRadius() const { return m_radius; }
    double getStep() const { return m_step; }
private:
    Point3D m_center;
    double m_radius;
    double m_step;
};

