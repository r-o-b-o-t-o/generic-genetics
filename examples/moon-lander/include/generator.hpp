#pragma once

#include "bot_lander.hpp"
#include <string>

class Generator {
public:
    Generator(int size, int popSize);
    BotLander operator()() const;
    float genRandomThrust() const;
    float genRandomAngle(float angle) const;

    const int size;
    const int popSize;

private:
    std::vector<std::pair<float, float>> genRandomCommands(int) const;
};
