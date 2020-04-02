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

        for (int i = 0; i < solution.length(); ++i) {
            if (GenericGenetics::Random::getInt(0, 100) < 10) {
                s[i] = alphanum[GenericGenetics::Random::getInt(0, alphanum.length() - 1)];
            }
        }

        return s;
    }
};

int MyGenerator::SIZE = 0;

int main() {
    std::string solution = "Thibaut est un sacrer fdp, j'ai jurer wola.";
    MyEvaluator e(solution);
    MyGenerator g(solution.length());
    GenericGenetics::Selector::Elitism<std::string> s(100);
    MyCrossover c;
    MyMutation m;
    GenericGenetics::Criterion::Mark f(43.0);

    std::string r = GenericGenetics::generate<std::string>(g, e, s, c, m, f);

    std::cout << r << std::endl;
    return 0;
}
