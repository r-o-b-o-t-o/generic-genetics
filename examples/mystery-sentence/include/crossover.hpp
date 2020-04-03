#pragma once

#include <string>
#include <vector>

class Crossover {
public:
    std::string operator()(const std::string& parent1,
                           const std::string& parent2) const;
};
