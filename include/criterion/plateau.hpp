#pragma once

#include <vector>

namespace GenericGenetics {
namespace Criterion {

class Plateau {
public:
    Plateau(int maxIterations);

    bool operator()(std::vector<float>& ratings);

private:
    int count;
    float prevRating;
    int maxIterations;
};

} // namespace Criterion
} // namespace GenericGenetics
