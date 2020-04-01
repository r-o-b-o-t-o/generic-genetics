#include "MyEvaluator.hpp"

float MyEvaluator::operator()(std::string& s) const {
    float val = 0.0;
    std::string solution = "hello";
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == solution[i])
            val += 1.0;
    }

    return val;
}