#pragma once

#include <string>
#include <vector>

class MyCrossover {
  public:
    std::string operator()(const std::string&, const std::string&) const;
};
