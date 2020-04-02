#ifndef MYEVALUATOR_HPP
#define MYEVALUATOR_HPP

#include <string>

class MyEvaluator {
public:
    float operator()(const std::string&) const;
};

#endif