#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

template <typename T, typename G, typename E, typename S, typename C,
          typename M, typename F>
T generate(const G& generator, const E& evaluator, const S& selector,
           const C& crossover, const M& mutation, const F& stopCrit) {
    std::vector<T> pop;
    std::vector<float> notes;

    for (int i = 0; i < 10; ++i) {
        pop.push_back(generator());
    }

    for (auto& p : pop) {
        notes.push_back(evaluator(p));
    }

    /*while (!stopCrit(notes)) {
        pop = selector(pop, notes);
        pop = crossover(pop);
        pop = mutation(pop);
        notes.clear();
        for (auto& p : pop) {
            notes.push_back(evaluator(p));
        }
    }*/

    auto it = max_element(std::begin(notes), std::end(notes));

    return pop[std::distance(notes.begin(), it)];
}
