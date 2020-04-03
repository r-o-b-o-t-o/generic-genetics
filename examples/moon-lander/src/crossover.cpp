#include "crossover.hpp"
#include "generator.hpp"

#include "../../../include/random.hpp"

std::vector<std::pair<float, float>> Crossover::operator()(
    const std::vector<std::pair<float, float>>& parent1,
    const std::vector<std::pair<float, float>>& parent2) const {
    std::vector<std::pair<float, float>> result = parent1;
    size_t len = result.size();
    size_t pos = GenericGenetics::Random::getInt(0, len - 1);
    size_t replaceLength = GenericGenetics::Random::getInt(1, len - pos);
    // result.replace(pos, replaceLength, parent2, pos, replaceLength);
    for (int i = pos; i < pos + replaceLength; ++i) {
        result[i] = parent2[i];
    }

    return result;
}
