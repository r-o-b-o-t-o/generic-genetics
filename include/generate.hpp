#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

#include "random.hpp"

namespace GenericGenetics {

template <typename T, typename G, typename E, typename S, typename C,
          typename M, typename F>
T generate(const G& generator, const E& evaluator, const S& selector,
           const C& crossover, const M& mutation, const F& stopCrit) {
    std::vector<T> pop;
    std::vector<float> notes;

    for (int i = 0; i < NB; ++i) {
        pop.push_back(generator());
    }

    for (T& p : pop) {
        notes.push_back(evaluator(p));
    }

    int i = 0;
    while (!stopCrit(notes)) {
        pop = selector(pop, notes);
        while (pop.size() < NB) {
            size_t popSize = pop.size();
            int id1 = Random::getInt(0, popSize - 1);
            int id2 = Random::getInt(0, popSize - 1);
            if (id1 == id2) {
                id2 = (id2 + 1) % popSize;
            }
            pop.push_back(crossover(pop[id1], pop[id2]));
        }
        for (int i = 0; i < pop.size(); ++i) {
            if (Random::getInt(0, 100) < 30) {
                pop[i] = mutation(pop[i]);
            }
        }
        notes.clear();
        for (T& p : pop) {
            notes.push_back(evaluator(p));
        }

        auto it = max_element(std::begin(notes), std::end(notes));
        std::cout << pop[std::distance(notes.begin(), it)] << std::endl;
        i++;
    }

    auto it = max_element(std::begin(notes), std::end(notes));

    std::cout << "Finished in " << i << " iterations" << std::endl;

    return pop[std::distance(notes.begin(), it)];
}

} // namespace GenericGenetics
