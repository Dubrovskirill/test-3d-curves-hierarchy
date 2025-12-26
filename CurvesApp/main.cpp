#include <iostream>
#include <vector>
#include <iomanip>
#include "Parser.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"

int main() {
    
    std::string testPath = "data/curves_to_check.txt";
    auto curves = Parser::parseFile(testPath);

    std::cout << "=== PARSER DATA INTEGRITY TEST ===" << std::endl;
    std::cout << std::fixed << std::setprecision(2);

    if (curves.empty()) {
        std::cout << "Failed to load curves or file is empty!" << std::endl;
        return 1;
    }

    for (const auto& curve : curves) {
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "Type: " << std::left << std::setw(10) << curve->getName()
            << " ID: " << curve->getId() << std::endl;

     

        if (auto c = std::dynamic_pointer_cast<Circle>(curve)) {
            std::cout << "[CIRCLE]  Radius: " << c->getRadius() << std::endl;
        }
        else if (auto e = std::dynamic_pointer_cast<Ellipse>(curve)) {
            std::cout << "[ELLIPSE] RadiusX: " << e->getRadiusX()
                << " RadiusY: " << e->getRadiusY() << std::endl;
        }
        else if (auto h = std::dynamic_pointer_cast<Helix>(curve)) {
            std::cout << "[HELIX]   Radius: " << h->getRadius()
                << " Step: " << h->getStep() << std::endl;
        }
    }
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Total curves parsed: " << curves.size() << std::endl;

    return 0;
}