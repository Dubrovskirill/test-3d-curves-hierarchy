#include "Parser.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>


std::vector<std::shared_ptr<ICurve>> Parser::parseFile(const std::string& filePath) {
    std::vector<std::shared_ptr<ICurve>> curves;
    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filePath << std::endl;
        return curves;
    }

    size_t count = 0;
    if (!(file >> count)) {
        return curves;
    }

    
    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        try {
            auto curve = createCurveFromLine(line);
            if (curve) {
                curves.push_back(curve);
            }
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "Validation Error: " << e.what() << " (Line skipped)" << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "General Error: " << e.what() << std::endl;
        }
    }

    return curves;
}

std::shared_ptr<ICurve> Parser::createCurveFromLine(const std::string& line) {
    std::stringstream ss(line);
    char type;
    uint64_t id;
    std::string name;
    double x, y, z;

    
    if (!(ss >> type >> id >> std::quoted(name) >> x >> y >> z)) {
        return nullptr;
    }

    Point3D center(x, y, z);

    if (type == 'C') {
        double r;
        if (ss >> r) return std::make_shared<Circle>(id, name, center, r);
    }
    else if (type == 'E') {
        double rx, ry;
        if (ss >> rx >> ry) return std::make_shared<Ellipse>(id, name, center, rx, ry);
    }
    else if (type == 'H') {
        double r, step;
        if (ss >> r >> step) return std::make_shared<Helix>(id, name, center, r, step);
    }

    return nullptr;
}