#ifndef MYEVALUATOR_HPP
#define MYEVALUATOR_HPP

#include <string>

class MyEvaluator {
public:
    MyEvaluator(const std::string&);
    float operator()(const std::string&) const;
private:
    std::string solution;
};

#endif