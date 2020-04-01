#include "MyGenerator.hpp"
#include "random.hpp"
#include <stdlib.h>
#include <iostream>

void gen_random(char* s, const int len) {
    static const char alphanum[] = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < len; ++i) {
        s[i] = alphanum[GenericGenetics::Random::getInt(0, sizeof(alphanum) - 1)];
    }

    s[len] = 0;
}

std::string MyGenerator::operator()() const {
    char s[SIZE];
    gen_random(s, SIZE);
    return std::string(s);
}