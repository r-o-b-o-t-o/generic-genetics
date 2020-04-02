#pragma once

#include <vector>

namespace GenericGenetics {
namespace Criterion {

class Mark {
public:
    Mark(float maxRating);

    bool operator()(std::vector<float>& ratings);

private:
    float maxRating;
};

} // namespace Criterion
} // namespace GenericGenetics
