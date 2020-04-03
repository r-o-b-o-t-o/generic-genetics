#include "mutation.hpp"
#include "generator.hpp"

#include "../../../include/random.hpp"

Mutation::Mutation(Generator* generator) : generator(generator) {}

void Mutation::operator()(
    std::vector<std::pair<float, float>>& solution) const {
    for (int i = 0; i < solution.size(); ++i) {
        if (GenericGenetics::Random::getInt(0, 99) < 10) {
            solution[i].first =
                this->generator->genRandomAngle(solution[i].first);
        }

        if (GenericGenetics::Random::getInt(0, 99) < 10) {
            solution[i].second =
                this->generator->genRandomAngle(solution[i].second);
        }
    }
}
