#pragma once

#include <string>

#include "generator.hpp"

class Evaluator {
public:
    Evaluator(Generator* generator);
    float operator()(const BotLander& s) const;

private:
    Generator* generator;
};
