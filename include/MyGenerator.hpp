#ifndef MYGENERATOR_HPP
#define MYGENERATOR_HPP

#include <string>

static const int NB = 100;
static const std::string alphanum = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz .,'";

class MyGenerator {
  public:
    MyGenerator(int);
    std::string operator()() const;
    static int SIZE;
};

#endif