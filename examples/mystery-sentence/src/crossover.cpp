#include "crossover.hpp"
#include "generator.hpp"

#include "../../../include/random.hpp"

std::string Crossover::operator()(const std::string& parent1,
                                  const std::string& parent2) const {
    std::string result = parent1;
    size_t len = result.length();
    size_t pos = GenericGenetics::Random::getInt(0, len - 1);
    size_t replaceLength = GenericGenetics::Random::getInt(1, len - pos);
    result.replace(pos, replaceLength, parent2, pos, replaceLength);

    return result;
}
