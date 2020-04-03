#pragma once

#include <vector>

namespace GenericGenetics {
namespace Criterion {

class Plateau {
public:
    Plateau(int maxIterations)
        : maxIterations(maxIterations), count(0), prevRating(0.0) {}

    bool operator()(std::vector<float>& ratings) {
        float max = 0.0;
        for (float& r : ratings) {
            if (r > max) {
                max = r;
            }
        }

        if (max == this->prevRating) {
            this->count++;
        } else {
            this->prevRating = max;
            this->count = 0;
        }
        return this->count > this->maxIterations;
    }

private:
    int count;
    float prevRating;
    int maxIterations;
};

} // namespace Criterion
} // namespace GenericGenetics
