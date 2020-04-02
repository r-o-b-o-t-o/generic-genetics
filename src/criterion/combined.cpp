#include "criterion/combined.hpp"

namespace GenericGenetics {
namespace Criterion {

Combined::Combined(int maxIterations, float maxRating, int plateauMaxIterations)
    : iterations(maxIterations),
      mark(maxRating),
      plateau(plateauMaxIterations) {}

bool Combined::operator()(std::vector<float>& ratings) {
    return this->iterations(ratings) || this->mark(ratings) || this->plateau(ratings);
}

} // namespace Criterion
} // namespace GenericGenetics
