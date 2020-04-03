#include "generator.hpp"

#include "../../../include/random.hpp"

Generator::Generator(int size, int popSize)
    : size(size),
      popSize(popSize),
      alphanum("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz .,'") {}

void Generator::genRandom(char* s, const int len) const {
    for (int i = 0; i < len; ++i) {
        s[i] =
            alphanum[GenericGenetics::Random::getInt(0, alphanum.length() - 1)];
    }

    s[len] = 0;
}

std::string Generator::operator()() const {
    char s[this->size];
    this->genRandom(s, this->size);
    return std::string(s);
}
