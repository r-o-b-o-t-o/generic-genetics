#include <iostream>

#include "generate.hpp"

class MyGenerator {
  public:
    void operator()() const { std::cout << "test!\n"; }
};
class MyEvaluator {};
class MySelector {};
class MyCrossover {};
class MyMutation {};
class MyStopCriterion {};

struct Result {};

int main() {
    MyGenerator g;
    MyEvaluator e;
    MySelector s;
    MyCrossover c;
    MyMutation m;
    MyStopCriterion f;
    Result r = generate<Result>(g, e, s, c, m, f);

    return 0;
}
