#pragma once

#include <iostream>

template <typename T, typename G, typename E, typename S, typename C,
          typename M, typename F>
T generate(G generator, E evaluator, S selector, C crossover, M mutation,
           F stopCrit) {
    generator();

    T t;
    return t;
}
