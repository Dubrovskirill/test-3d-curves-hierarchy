#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <numeric> 
#include <memory>
#include <cmath>

#include "Parser.h"
#include "Circle.h"

int main(int argc, char* argv[]) {
  
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <path_to_file>" << std::endl;
        return 1;
    }

    static const double PI = std::acos(-1.0);
    const double t = PI / 4.0;

    auto allCurves = Parser::parseFile(argv[1]);

    if (allCurves.empty()) {
        std::cout << "No valid curves found." << std::endl;
        return 0;
    }

    std::cout << std::fixed << std::setprecision(6);

    std::cout << "Curves Data at t = PI/4 " << std::endl;
    for (const auto& curve : allCurves) {
        std::cout << "ID: " << std::setw(10) << curve->getId()
            << " [" << std::left << std::setw(15) << curve->getName() << "]"
            << "\n  Point: " << curve->getPoint(t)
            << "\n  Deriv: " << curve->getDerivative(t) << "\n" << std::endl;
    }

    
    std::vector<std::shared_ptr<Circle>> circles;
    for (const auto& curve : allCurves) {
        if (auto circlePtr = std::dynamic_pointer_cast<Circle>(curve)) {
            circles.push_back(circlePtr);
        }
    }

 
    std::sort(circles.begin(), circles.end(),
        [](const std::shared_ptr<Circle>& a, const std::shared_ptr<Circle>& b) {
            return a->getRadius() < b->getRadius();
        });

    std::cout << "Sorted Circles (by radius) " << std::endl;
    for (const auto& circle : circles) {
        std::cout << "Radius: " << std::setw(10) << circle->getRadius()
            << " | ID: " << circle->getId() << std::endl;
    }

   

    double totalRadiusSum = std::accumulate(circles.begin(), circles.end(), 0.0,
        [](double sum, const std::shared_ptr<Circle>& c) {
            return sum + c->getRadius();
        });

    std::cout << "\nTotal Sum of Radius " << std::endl;
    std::cout << "Sum: " << totalRadiusSum << std::endl;

    return 0;
}