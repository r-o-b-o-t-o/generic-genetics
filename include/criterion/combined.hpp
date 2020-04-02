#pragma once

#include <vector>

#include "iterations.hpp"
#include "mark.hpp"
#include "plateau.hpp"

namespace GenericGenetics {
namespace Criterion {

class Combined {
public:
    Combined(int maxIterations, float maxRating, int plateauMaxIterations);

    bool operator()(std::vector<float>& notes);

private:
    Iterations iterations;
    Mark mark;
    Plateau plateau;
};

} // namespace Criterion
} // namespace GenericGenetics
