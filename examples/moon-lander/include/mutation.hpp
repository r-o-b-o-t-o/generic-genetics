#pragma once

#include <string>

#include "generator.hpp"

class Mutation {
public:
    Mutation(Generator* generator);

    void operator()(std::vector<std::pair<float, float>>& solution) const;

private:
    Generator* generator;
};
