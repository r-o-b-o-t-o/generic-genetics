#pragma once

#include "criterion.hpp"
#include "selectors.hpp"

namespace GenericGenetics {

template <typename T, typename G, typename E, typename S, typename C,
          typename M, typename F>
class GeneticAlgorithm {
public:
    GeneticAlgorithm(G g, E e, S s, C c, M m, F f) {
        this->g = g;
        this->e = e;
        this->s = s;
        this->c = c;
        this->m = m;
        this->f = f;
    }

    T run(int popSize) {
        return GenericGenetics::generate<std::string>(*g, *e, *s, *c, *m, *f,
                                                      popSize);
    }

private:
    G g;
    E e;
    S s;
    C c;
    M m;
    F f;
};

template <typename T, typename G, typename E, typename C, typename M>
class GeneticAlgorithm<T, G, E, GenericGenetics::Selector::Tournament<T>*, C, M,
                       GenericGenetics::Criterion::Iterations*> {
public:
    GeneticAlgorithm(int nbIter, G g, E e,
                     GenericGenetics::Selector::Tournament<T>* s, C c, M m) {
        this->g = g;
        this->e = e;
        this->s = s;
        this->c = c;
        this->m = m;
        this->f = new GenericGenetics::Criterion::Iterations(nbIter);
    }

    T run(int popSize) {

        return GenericGenetics::generate<std::string>(*g, *e, *s, *c, *m, *f,
                                                      popSize);
    }

private:
    G g;
    E e;
    GenericGenetics::Selector::Tournament<T>* s;
    C c;
    M m;
    GenericGenetics::Criterion::Iterations* f;
};

} // namespace GenericGenetics
