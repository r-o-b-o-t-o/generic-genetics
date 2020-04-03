#pragma once

#include "lander.hpp"

class BotLander : Lander {
public:
    BotLander(std::vector<std::pair<float, float>>);
private:
    std::vector<std::pair<float, float>> commands;
};