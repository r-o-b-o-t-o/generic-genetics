#pragma once

#include <algorithm>
#include <vector>

namespace GenericGenetics {
namespace Selector {

template <typename T>
class Tournament {
public:
    Tournament(int nbParticipants, int tournamentRounds)
        : nbParticipants(nbParticipants), tournamentRounds(tournamentRounds) {}

    int getNbParticipants() { return this->nbParticipants; }
    void setNbParticipants(int nbParticipants) {
        this->nbParticipants = nbParticipants;
    }

    int getTournamentRounds() { return this->tournamentRounds; }
    void setTournamentRounds(int tournamentRounds) {
        this->tournamentRounds = tournamentRounds;
    }

    std::vector<T> operator()(const std::vector<T>& pop,
                              const std::vector<float>& ratings) const {
        std::vector<T> selected;
        std::vector<int> selectedIndices;

        std::vector<int> participants;
        participants.reserve(this->nbParticipants);

        while (participants.size() != this->nbParticipants) {
            participants.clear();
            size_t n = pop.size();
            assert(n == ratings.size());
            assert(n >= this->nbParticipants);

            for (int i = 0; i < this->nbParticipants; ++i) {
                int randParticipant;
                do {
                    randParticipant = Random::getInt(0, n - 1);
                } while (std::find(participants.begin(), participants.end(),
                                   randParticipant) != participants.end());
                participants.push_back(randParticipant);
            }

            int best = -1;
            float bestRating = 0.0f;
            for (int i = 0; i < this->nbParticipants; ++i) {
                if (best == -1 || ratings[participants[i]] > bestRating) {
                    best = participants[i];
                    bestRating = ratings[participants[i]];
                }
            }
            if (best != -1) {
                selected.push_back(pop[best]);
                selectedIndices.push_back(best);
            }
        }

        return selected;
    }

private:
    int nbParticipants;
    int tournamentRounds;
};

} // namespace Selector
} // namespace GenericGenetics
