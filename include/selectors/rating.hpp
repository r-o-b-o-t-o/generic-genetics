#pragma once

#include <vector>

namespace GenericGenetics {
namespace Selector {

template <typename T>
class Rating {
public:
    Rating(int n) : n(n) {}

    int getN() { return this->n; }
    void setN(int n) { this->n = n; }

    std::vector<T> operator()(const std::vector<T>& pop,
                              const std::vector<float>& ratings) const {
        std::vector<T> selected;
        selected.reserve(this->n);
        std::vector<int> selectedIndices;
        selectedIndices.reserve(this->n);

        int idx;
        for (int i = 0; i < this->n; ++i) {
            do {
                idx = Random::getWeightedRandomItem(ratings);
            } while (std::find(selectedIndices.begin(), selectedIndices.end(),
                               idx) != selectedIndices.end());
            selectedIndices.push_back(idx);
            selected.push_back(pop[idx]);
        }
        /*for (int i = 0; i < selectedIndices.size(); ++i) {
            std::cout << selectedIndices[i] << " ";
        }
        std::cout << "\n";*/
        return selected;
    }

private:
    int n;
};

} // namespace Selector
} // namespace GenericGenetics
