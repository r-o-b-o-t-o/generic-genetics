#include "MyCrossover.hpp"
#include "MyGenerator.hpp"
#include "random.hpp"

std::string MyCrossover::operator()(std::string& solution1, std::string& solution2) const {
    int middle = GenericGenetics::Random::getInt(0, SIZE - 3) + 1;
    std::string str = solution1;

    for (int i = middle; i < str.length(); ++i) {
        str[i] = solution2[i];
    }

    return str;
}