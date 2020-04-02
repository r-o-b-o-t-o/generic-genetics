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
    std::vector<float> notes;

    for (int i = 0; i < NB; ++i) {
        pop.push_back(generator());
    }

    for (T& p : pop) {
        notes.push_back(evaluator(p));
    }

    int i = 0;
    while (!stopCrit(notes)) {
        parents = selector(pop, notes);
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
        notes.clear();
        for (T& p : pop) {
            notes.push_back(evaluator(p));
        }

        auto it = max_element(std::begin(notes), std::end(notes));
        std::cout << "best individual: " << pop[std::distance(notes.begin(), it)] << " (with a rating of " << *it << ")" << std::endl;
        i++;
    }

    auto it = max_element(std::begin(notes), std::end(notes));

    std::cout << "Finished in " << i << " iterations" << std::endl;

    return pop[std::distance(notes.begin(), it)];
}

} // namespace GenericGenetics
