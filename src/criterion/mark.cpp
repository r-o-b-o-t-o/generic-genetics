#include "criterion/mark.hpp"

namespace GenericGenetics {
namespace Criterion {

Mark::Mark(float maxNote) : maxNote(maxNote) {}

bool Mark::operator()(std::vector<float>& notes) {
    for (float& note : notes) {
        if (note >= this->maxNote) {
            return true;
        }
    }
    return false;
}

} // namespace Criterion
} // namespace GenericGenetics
