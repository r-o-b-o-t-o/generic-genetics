#include "mutation.hpp"
#include "generator.hpp"

#include "../../../include/random.hpp"

Mutation::Mutation(Generator* generator) : generator(generator) {}

void Mutation::operator()(
    BotLander& solution) const {
    for (int i = 0; i < solution.commands.size(); ++i) {
        if (GenericGenetics::Random::getInt(0, 99) < 10) {
            solution.commands[i].first =
                this->generator->genRandomAngle(solution.commands[i].first);
        }

        if (GenericGenetics::Random::getInt(0, 99) < 10) {
            solution.commands[i].second =
                this->generator->genRandomAngle(solution.commands[i].second);
        }
    }
}
