#include "MyCrossover.hpp"
#include "MyGenerator.hpp"
#include "random.hpp"

std::string MyCrossover::operator()(const std::string& solution1, const std::string& solution2) const {
    std::string result = solution1;
    size_t len = result.length();
    size_t pos = GenericGenetics::Random::getInt(0, len - 1);
    size_t replaceLength = GenericGenetics::Random::getInt(1, len - pos);
    result.replace(pos, replaceLength, solution2, pos, replaceLength);

    return result;
}
