#include "MyGenerator.hpp"
#include "random.hpp"
#include <stdlib.h>
#include <iostream>

MyGenerator::MyGenerator(int s) {
    this->SIZE = s;
}

void gen_random(char* s, const int len) {

    for (int i = 0; i < len; ++i) {
        s[i] = alphanum[GenericGenetics::Random::getInt(0, alphanum.length() - 1)];
    }

    s[len] = 0;
}

std::string MyGenerator::operator()() const {
    char s[this->SIZE];
    gen_random(s, this->SIZE);
    return std::string(s);
}
