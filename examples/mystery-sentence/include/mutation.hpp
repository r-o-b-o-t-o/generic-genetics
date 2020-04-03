#pragma once

#include <string>

#include "generator.hpp"

class Mutation {
public:
    Mutation(Generator* generator);

    void operator()(std::string& solution) const;

private:
    Generator* generator;
};
