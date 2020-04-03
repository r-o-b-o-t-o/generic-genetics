#pragma once

#include <vector>

#include "iterations.hpp"
#include "mark.hpp"
#include "plateau.hpp"

namespace GenericGenetics {
namespace Criterion {

class Combined {
public:
    Combined(int maxIterations, float maxRating, int plateauMaxIterations)
        : iterations(maxIterations),
          mark(maxRating),
          plateau(plateauMaxIterations) {}

    bool operator()(std::vector<float>& ratings) {
        return this->iterations(ratings) || this->mark(ratings) ||
               this->plateau(ratings);
    }

private:
    Iterations iterations;
    Mark mark;
    Plateau plateau;
};

} // namespace Criterion
} // namespace GenericGenetics
