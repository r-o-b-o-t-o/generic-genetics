#pragma once

#include <vector>

namespace GenericGenetics {
namespace Criterion {

class Mark {
public:
    Mark(float maxRating) : maxRating(maxRating) {}

    bool operator()(std::vector<float>& ratings) {
        for (float& rating : ratings) {
            if (rating >= this->maxRating) {
                return true;
            }
        }
        return false;
    }

private:
    float maxRating;
};

} // namespace Criterion
} // namespace GenericGenetics
