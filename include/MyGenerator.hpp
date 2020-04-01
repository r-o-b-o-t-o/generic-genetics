#ifndef MYGENERATOR_HPP
#define MYGENERATOR_HPP

#include <string>

class MyGenerator {
  public:
    std::string operator()() const;
};

#endif