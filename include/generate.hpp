#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

#include "random.hpp"

namespace GenericGenetics {

template <typename T, typename G, typename E, typename S, typename C,
          typename M, typename F>
T generate(const G& generator, const E& evaluator, const S& selector,
           const C& crossover, const M& mutation, F& stopCrit) {
    std::vector<T> pop;
    std::vector<T> parents;
    std::vector<float> ratings;

    for (int i = 0; i < NB; ++i) {
        pop.push_back(generator());
    }

    for (T& p : pop) {
        ratings.push_back(evaluator(p));
    }

    int i = 0;
    while (!stopCrit(ratings)) {
        parents = selector(pop, ratings);
        size_t parentsSize = parents.size();

        // New generation from the fittest individuals of the previous population
        pop.clear();
        for (int j = 0; j < NB; ++j) {
            int id1 = Random::getInt(0, parentsSize - 1);
            int id2 = Random::getInt(0, parentsSize - 1);
            if (id1 == id2) {
                id2++;
                id2 %= parentsSize;
            }
            T child = crossover(parents[id1], parents[id2]);
            if (Random::getInt(0, 100) < 30) {
                child = mutation(child);
            }
            pop.push_back(child);
        }

        // Calculate fitness of new generation
        ratings.clear();
        for (T& p : pop) {
            ratings.push_back(evaluator(p));
        }

        i++;
    }

    auto it = max_element(std::begin(ratings), std::end(ratings));

    std::cout << "Finished in " << i << " iterations" << std::endl;

    return pop[std::distance(ratings.begin(), it)];
}

} // namespace GenericGenetics
