#include "criterion/mark.hpp"

namespace GenericGenetics {
namespace Criterion {

Mark::Mark(float maxRating) : maxRating(maxRating) {}

bool Mark::operator()(std::vector<float>& ratings) {
    for (float& rating : ratings) {
        if (rating >= this->maxRating) {
            return true;
        }
    }
    return false;
}

} // namespace Criterion
} // namespace GenericGenetics
