#include <iostream>
#include <ctime>

#include "MyGenerator.hpp"
#include "MyEvaluator.hpp"
#include "generate.hpp"


class MySelector {};
class MyCrossover {};
class MyMutation {};
class MyStopCriterion {
  public:
    bool operator()(std::vector<float>& notes) const {
      for (auto &note : notes) {
        if (note >= 5.0)
          return true;
      }
      return false;
    }
};


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
