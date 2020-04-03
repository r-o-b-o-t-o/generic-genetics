#pragma once

#include "lander.hpp"

class BotLander : Lander {
public:
    BotLander(std::vector<std::pair<float, float>>);
    std::vector<std::pair<float, float>> commands;
    void setAngle(float);
    void setThrust(float);
};
