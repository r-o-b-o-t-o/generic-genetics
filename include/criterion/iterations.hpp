#pragma once

#include <vector>

namespace GenericGenetics {
namespace Criterion {

class Iterations {
public:
    Iterations(int maxIterations);

    bool operator()(std::vector<float>& notes);

private:
    int count;
    int maxIterations;
};

} // namespace Criterion
} // namespace GenericGenetics
