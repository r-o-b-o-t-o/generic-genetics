#ifndef MYCROSSOVER_HPP
#define MYCROSSOVER_HPP

#include <string>
#include <vector>

class MyCrossover {
  public:
    std::string operator()(const std::string&, const std::string&) const;
};

#endif