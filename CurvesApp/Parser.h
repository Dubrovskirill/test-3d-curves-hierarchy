#pragma once
#include <vector>
#include <memory>
#include <string>
#include "ICurve.h"
class Parser
{
public:
    
    static std::vector<std::shared_ptr<ICurve>> parseFile(const std::string& filePath);

private:
    static std::shared_ptr<ICurve> createCurveFromLine(const std::string& line);
};

