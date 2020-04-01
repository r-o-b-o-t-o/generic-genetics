#pragma once

#include <iostream>

template <typename T, typename G, typename E, typename S, typename C,
          typename M, typename F>
T generate(const G& generator, const E& evaluator, const S& selector, const C& crossover, const M& mutation,
           const F& stopCrit) {
    generator();

    T t;
    return t;
}
