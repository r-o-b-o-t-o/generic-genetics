#pragma once

#include <vector>

namespace GenericGenetics {
namespace Criterion {

class Mark {
public:
    Mark(float maxNote);

    bool operator()(std::vector<float>& notes);

private:
    float maxNote;
};

} // namespace Criterion
} // namespace GenericGenetics
