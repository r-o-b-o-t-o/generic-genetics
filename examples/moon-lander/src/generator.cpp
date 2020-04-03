#include "generator.hpp"
#include <algorithm>
#include <math.h>

#include "../../../include/random.hpp"

Generator::Generator(int size, int popSize) : size(size), popSize(popSize) {}

float Generator::genRandomThrust() const {
    return round(GenericGenetics::Random::getFloat(0, 1));
}

float Generator::genRandomAngle(float angle) const {
    angle += GenericGenetics::Random::getFloat(-2, 2);
    angle = std::min(angle, 90.0f);
    return angle = std::max(angle, -90.0f);
}

std::vector<std::pair<float, float>>
Generator::genRandomCommands(int size) const {
    std::vector<std::pair<float, float>> actions;
    float angle = -90.0;
    for (int i = 0; i < size; ++i) {
        angle = this->genRandomAngle(angle);
        actions.push_back(std::make_pair(angle, this->genRandomThrust()));
    }

    return actions;
}

BotLander Generator::operator()() const {

    return BotLander(this->genRandomCommands(this->size));
}
