#pragma once

#include <string>

#include "generator.hpp"

class Evaluator {
public:
    Evaluator(const std::string& s, Generator* generator);
    float operator()(const std::string& s) const;

private:
    std::string solution;
    Generator* generator;
};
