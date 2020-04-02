#pragma once

#include <vector>

namespace GenericGenetics {
namespace Criterion {

class Plateau {
public:
    Plateau(int maxIterations);

    bool operator()(std::vector<float>& notes);

private:
    int count;
    float prevNote;
    int maxIterations;
};

} // namespace Criterion
} // namespace GenericGenetics
