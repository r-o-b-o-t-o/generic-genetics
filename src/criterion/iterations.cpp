#include "criterion/iterations.hpp"

namespace GenericGenetics {
namespace Criterion {

Iterations::Iterations(int maxIterations)
    : maxIterations(maxIterations), count(0) {}

bool Iterations::operator()(std::vector<float>& ratings) {
    this->count++;
    return this->count > this->maxIterations;
}

} // namespace Criterion
} // namespace GenericGenetics
