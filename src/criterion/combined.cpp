#include "criterion/combined.hpp"

namespace GenericGenetics {
namespace Criterion {

Combined::Combined(int maxIterations, float maxRating, int plateauMaxIterations)
    : iterations(maxIterations),
      mark(maxRating),
      plateau(plateauMaxIterations) {}

bool Combined::operator()(std::vector<float>& notes) {
    return this->iterations(notes) || this->mark(notes) || this->plateau(notes);
}

} // namespace Criterion
} // namespace GenericGenetics
