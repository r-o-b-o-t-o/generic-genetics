#include <iostream>

#include "MyCrossover.hpp"
#include "MyEvaluator.hpp"
#include "MyGenerator.hpp"
#include "generate.hpp"
#include "selectors.hpp"
#include "criterion.hpp"

class MyMutation {
public:
    std::string operator()(const std::string& solution) const {
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

int main() {
    MyGenerator g;
    MyEvaluator e;
    GenericGenetics::Selector::Elitism<std::string> s(100);
    MyCrossover c;
    MyMutation m;
    GenericGenetics::Criterion::Plateau f(5);

    std::string r = GenericGenetics::generate<std::string>(g, e, s, c, m, f);

    std::cout << r << std::endl;
    return 0;
}
