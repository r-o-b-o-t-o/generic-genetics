#include <ctime>
#include <iostream>

#include "MyEvaluator.hpp"
#include "MyGenerator.hpp"
#include "MyCrossover.hpp"
#include "generate.hpp"
#include "selectors.hpp"

class MyMutation {
  public:
    std::string operator()(std::string& solution) const {
      std::string s = solution;
      static const char alphanum[] = "abcdefghijklmnopqrstuvwxyz";
      for (int i = 0; i < solution.length(); ++i) {
        if (rand() % 100 < 10) {
          s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
        }
      }

      return s;
    }
};
class MyStopCriterion {
  public:
    bool operator()(std::vector<float>& notes) const {
      for (auto &note : notes) {
        if (note >= 21.0)
          return true;
      }
      return false;
    }
};

int main() {
    MyGenerator g;
    MyEvaluator e;
    GenericGenetics::Selector::Elitism<std::string> s(5);
    MyCrossover c;
    MyMutation m;
    MyStopCriterion f;

    std::srand(std::time(nullptr));
    std::string r = generate<std::string>(g, e, s, c, m, f);

    std::cout << r << std::endl;
    return 0;
}
