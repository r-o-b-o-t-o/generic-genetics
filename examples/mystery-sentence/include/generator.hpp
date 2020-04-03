#pragma once

#include <string>

class Generator {
public:
    Generator(int size, int popSize);
    std::string operator()() const;
    const int size;
    const int popSize;
    const std::string alphanum;

private:
    void genRandom(char* s, const int len) const;
};
