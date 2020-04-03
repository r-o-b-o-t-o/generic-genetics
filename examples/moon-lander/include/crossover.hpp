#pragma once

#include <string>
#include <vector>

#include "bot_lander.hpp"

class Crossover {
public:
    BotLander
    operator()(const BotLander& parent1,
               const BotLander& parent2) const;
};
