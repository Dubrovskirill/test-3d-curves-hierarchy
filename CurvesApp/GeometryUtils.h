#pragma once
#include <iostream>

	struct Point3D
	{
		double x = 0.0;
		double y = 0.0;
		double z = 0.0;

		Point3D(double x = 0.0, double y = 0.0, double z = 0.0)
			:x(x), y(y),z(z) { }
	};

	struct Vector3D
	{
		double x = 0.0;
		double y = 0.0;
		double z = 0.0;

		Vector3D(double x = 0.0, double y = 0.0, double z = 0.0)
			:x(x), y(y), z(z) {
		}
	};

	inline std::ostream& operator<<(std::ostream& os, const Point3D& p) {
		return os << "(" << p.x << "; " << p.y << "; " << p.z << ")";
	}

	inline std::ostream& operator<<(std::ostream& os, const Vector3D& v) {
		return os << "[" << v.x << ", " << v.y << ", " << v.z << "]";
	}



