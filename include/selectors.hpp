#include <assert.h>

#include <algorithm>
#include <tuple>
#include <vector>

namespace GenericGenetics {
namespace Selector {

template <typename T> class Elitism {
public:
    Elitism(int n) : n(n) {}

    int getN() { return this->n; }
    void setN(int n) { this->n = n; }

    std::vector<T> operator()(const std::vector<T>& pop,
                              const std::vector<float>& ratings) const {
        size_t size = pop.size();
        assert(size == ratings.size());
        assert(size >= this->n);

        std::vector<std::tuple<T, float>> paired;
        paired.reserve(size);
        for (size_t i = 0; i < size; ++i) {
            paired.push_back(std::make_tuple(pop[i], ratings[i]));
        }

        std::sort(paired.begin(), paired.end(), [](auto& lhs, auto& rhs) {
            return std::get<1>(lhs) > std::get<1>(rhs);
        });

        std::vector<T> selected;
        selected.reserve(this->n);
        for (size_t i = 0; i < this->n; ++i) {
            selected.push_back(std::get<0>(paired[i]));
        }

        return selected;
    }

private:
    int n;
};

class RandomByScore {};
class RandomByRank {};
class Tournament {};

} // namespace Selector
} // namespace GenericGenetics
