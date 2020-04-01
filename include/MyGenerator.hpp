#ifndef MYGENERATOR_HPP
#define MYGENERATOR_HPP

#include <string>

static const int NB = 10;
static const int SIZE = 21;

class MyGenerator {
  public:
    std::string operator()() const;
};

#endif