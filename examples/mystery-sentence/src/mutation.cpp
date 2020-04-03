#include "mutation.hpp"
#include "generator.hpp"

#include "../../../include/random.hpp"

Mutation::Mutation(Generator* generator) : generator(generator) {}

void Mutation::operator()(std::string& solution) const {
    for (int i = 0; i < solution.length(); ++i) {
        if (GenericGenetics::Random::getInt(0, 99) < 10) {
            solution[i] =
                this->generator->alphanum[GenericGenetics::Random::getInt(
                    0, this->generator->alphanum.length() - 1)];
        }
    }
}
