#include "MyCrossover.hpp"
#include "MyGenerator.hpp"

std::string MyCrossover::operator()(std::string& solution1, std::string& solution2) const {
    
    int middle = (rand() % (SIZE - 2)) + 1;
    std::string str = solution1;

    for (int i = middle; i < str.length(); ++i) {
        str[i] = solution2[i];
    }

    return str;
}