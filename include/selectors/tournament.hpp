#pragma once

#include <algorithm>
#include <vector>

namespace GenericGenetics {
namespace Selector {

template <typename T>
class Tournament {
public:
    Tournament(int m) : m(m) {}

    int getM() { return this->m; }
    void setM(int m) { this->m = m; }

    std::vector<T> operator()(const std::vector<T>& pop,
                              const std::vector<float>& ratings) const {
        std::vector<T*> participants;
        size_t n = pop.size();
        assert(n == ratings.size());
        assert(n >= this->m);

        participants.reserve(this->m);
        for (int i = 0; i < this->m; ++i) {
            T* randParticipant;
            do {
                randParticipant = (T*)&pop[Random::getInt(0, n - 1)];
            } while (std::find(participants.begin(), participants.end(),
                               randParticipant) != participants.end());
            participants.push_back(randParticipant);
        }

        std::vector<T> selected;
        T* best = nullptr;
        float bestRating = 0.0f;
        for (int i = 0; i < this->m; ++i) {
            if (best == nullptr || ratings[i] > bestRating) {
                best = participants[i];
                bestRating = ratings[i];
            }
        }
        if (best != nullptr) {
            selected.push_back(*best);
        }
        return selected;
    }

private:
    int m;
};

} // namespace Selector
} // namespace GenericGenetics
