#pragma once

#include <algorithm>
#include <map>
#include <numeric>
#include <vector>

namespace GenericGenetics {
namespace Selector {

template <typename T>
class Rank {
public:
    Rank(int n) : n(n) {}

    int getN() { return this->n; }
    void setN(int n) { this->n = n; }

    std::vector<T> operator()(std::vector<T>& pop,
                              std::vector<float>& ratings) const {
        std::vector<size_t> ranks = calculateRanks(ratings);
        std::vector<T> selected;
        selected.reserve(this->n);
        std::vector<int> selectedIndices;
        selectedIndices.reserve(this->n);

        int idx;
        for (int i = 0; i < this->n; ++i) {
            do {
                idx = Random::getWeightedRandomItem(ranks);
            } while (std::find(selectedIndices.begin(), selectedIndices.end(),
                               idx) != selectedIndices.end());
            selectedIndices.push_back(idx);
            selected.push_back(std::move(pop[idx]));
        }
        return selected;
    }

private:
    int n;

    template <typename X>
    static std::vector<size_t> calculateRanks(const std::vector<X>& values) {
        std::vector<size_t> result(values.size());
        // Sorted index
        std::vector<size_t> indx(values.size());
        std::iota(indx.begin(), indx.end(), 0);
        std::sort(indx.begin(), indx.end(), [&values](int i1, int i2) {
            return values[i1] < values[i2];
        });
        // Return ranking
        for (size_t iter = 0; iter < values.size(); ++iter) {
            result[indx[iter]] = iter + 1;
        }
        return result;
    }
};

} // namespace Selector
} // namespace GenericGenetics
