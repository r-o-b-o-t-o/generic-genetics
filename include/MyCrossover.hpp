#ifndef MYCROSSOVER_HPP
#define MYCROSSOVER_HPP

#include <string>
#include <vector>

class MyCrossover {
  public:
    std::string operator()(std::string&, std::string&) const;
};

#endif