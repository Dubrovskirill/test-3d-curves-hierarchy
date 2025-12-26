#pragma once
#include <string>
#include <cstdint>
#include "GeometryUtils.h"


class ICurve 
{
public:
 
    ICurve(uint64_t id, const std::string& name)
        : m_id(id), m_name(name) {
    }
    virtual ~ICurve() = default;

    virtual Point3D getPoint(double t) const = 0;
    virtual Vector3D getDerivative(double t) const = 0;

    uint64_t getId() const { return m_id; }
    std::string getName() const { return m_name; }

private:
    uint64_t m_id;
    std::string m_name;
};
