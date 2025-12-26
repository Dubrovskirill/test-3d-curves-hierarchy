#pragma once
#include <iostream>

namespace Geometry {
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
}


