#include "crossover.hpp"
#include "generator.hpp"

#include "../../../include/random.hpp"

BotLander Crossover::operator()(
    const BotLander& parent1,
    const BotLander& parent2) const {
    BotLander result = parent1;
    size_t len = result.commands.size();
    size_t pos = GenericGenetics::Random::getInt(0, len - 1);
    size_t replaceLength = GenericGenetics::Random::getInt(1, len - pos);
    // result.replace(pos, replaceLength, parent2, pos, replaceLength);
    for (int i = pos; i < pos + replaceLength; ++i) {
       result.commands[i] = parent2.commands[i];
    }

    return result;
}
