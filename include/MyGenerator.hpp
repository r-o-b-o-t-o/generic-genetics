#ifndef MYGENERATOR_HPP
#define MYGENERATOR_HPP

#include <string>

static const int NB = 1000;
static const int SIZE = 25;

class MyGenerator {
  public:
    std::string operator()() const;
};

#endif