#include <iostream>
#include <ctime>

#include "MyGenerator.hpp"
#include "MyEvaluator.hpp"
#include "generate.hpp"


class MySelector {};
class MyCrossover {};
class MyMutation {};
class MyStopCriterion {};


int main() {
    MyGenerator g;
    MyEvaluator e;
    MySelector s;
    MyCrossover c;
    MyMutation m;
    MyStopCriterion f;

    std::srand(std::time(nullptr));
    std::string r = generate<std::string>(g, e, s, c, m, f);

    std::cout << r << std::endl;
    return 0;
}
