#pragma once

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

} // namespace GenericGenetics