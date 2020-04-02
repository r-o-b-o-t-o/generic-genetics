#include <iostream>

#include "MyCrossover.hpp"
#include "MyEvaluator.hpp"
#include "MyGenerator.hpp"
#include "generate.hpp"
#include "selectors.hpp"

class MyMutation {
public:
    std::string operator()(std::string& solution) const {
        std::string s = solution;
        static const char alphanum[] = "abcdefghijklmnopqrstuvwxyz ";
        for (int i = 0; i < solution.length(); ++i) {
            if (GenericGenetics::Random::getInt(0, 100) < 10) {
                s[i] = alphanum[GenericGenetics::Random::getInt(0, sizeof(alphanum) - 2)];
            }
        }

        return s;
    }
};
class MyStopCriterion {
public:
    bool operator()(std::vector<float>& notes) const {
        for (auto& note : notes) {
            if (note >= 25.0)
                return true;
        }
        return false;
    }
};

int main() {
    MyGenerator g;
    MyEvaluator e;
    GenericGenetics::Selector::Elitism<std::string> s(100);
    MyCrossover c;
    MyMutation m;
    MyStopCriterion f;

    std::string r = GenericGenetics::generate<std::string>(g, e, s, c, m, f);

    std::cout << r << std::endl;
    return 0;
}
