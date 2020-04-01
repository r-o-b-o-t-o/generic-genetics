#include <ctime>
#include <iostream>

#include "MyEvaluator.hpp"
#include "MyGenerator.hpp"
#include "generate.hpp"
#include "selectors.hpp"

class MySelector {};
class MyCrossover {};
class MyMutation {};
class MyStopCriterion {};

int main() {
    MyGenerator g;
    MyEvaluator e;
    GenericGenetics::Selector::Elitism<int> s(1);
    MyCrossover c;
    MyMutation m;
    MyStopCriterion f;

    std::srand(std::time(nullptr));
    std::string r = generate<std::string>(g, e, s, c, m, f);

    std::cout << r << std::endl;
    return 0;
}
