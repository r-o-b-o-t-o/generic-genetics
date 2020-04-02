#include "criterion/plateau.hpp"

namespace GenericGenetics {
namespace Criterion {

Plateau::Plateau(int maxIterations)
    : maxIterations(maxIterations), count(0), prevNote(0.0) {}

bool Plateau::operator()(std::vector<float>& notes) {
    float max = 0.0;
    for (float& n : notes) {
        if (n > max)
            max = n;
    }

    if (max == this->prevNote) {
        this->count++;
    } else {
        this->prevNote = max;
        this->count = 0;
    }
    return this->count > this->maxIterations;
}

} // namespace Criterion
} // namespace GenericGenetics
