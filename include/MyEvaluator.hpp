#ifndef MYEVALUATOR_HPP
#define MYEVALUATOR_HPP

#include <string>

class MyEvaluator {
  public:
    float operator()(std::string&) const;
};

#endif