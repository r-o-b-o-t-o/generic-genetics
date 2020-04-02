#include "MyCrossover.hpp"
#include "MyGenerator.hpp"
#include "random.hpp"

std::string MyCrossover::operator()(const std::string& solution1, const std::string& solution2) const {
    int middle = GenericGenetics::Random::getInt(0, MyGenerator::SIZE - 3) + 1;
    std::string str = solution1;

    for (int i = middle; i < str.length(); ++i) {
        str[i] = solution2[i];
    }

    return str;
}
