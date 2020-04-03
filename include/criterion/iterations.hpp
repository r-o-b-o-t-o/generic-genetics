#pragma once

#include <vector>

namespace GenericGenetics {
namespace Criterion {

class Iterations {
public:
    Iterations(int maxIterations) : count(0), maxIterations(maxIterations) {}

    bool operator()(std::vector<float>& ratings) {
        this->count++;
        return this->count > this->maxIterations;
    }

private:
    int count;
    int maxIterations;
};

} // namespace Criterion
} // namespace GenericGenetics
