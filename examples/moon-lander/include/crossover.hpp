#pragma once

#include <string>
#include <vector>

class Crossover {
public:
    std::vector<std::pair<float, float>> operator()(const std::vector<std::pair<float, float>>& parent1,
                           const std::vector<std::pair<float, float>>& parent2) const;
};
