#include "crossover.hpp"
#include "evaluator.hpp"
#include "generator.hpp"
#include "mutation.hpp"

#include "../../../include/criterion.hpp"
#include "../../../include/generate.hpp"
#include "../../../include/geneticAlgorithm.hpp"
#include "../../../include/selectors.hpp"

int main() {
    // ---------------------using generate function---------------------
    /*std::string solution = "well hello there";
    Generator g(solution.length(), 1'000);
    Evaluator e(solution, &g);
    GenericGenetics::Selector::Rank<std::string> s(100);
    Crossover c;
    Mutation m(&g);
    GenericGenetics::Criterion::Mark f(static_cast<float>(solution.length()));

    std::string result =
        GenericGenetics::generate<std::string>(g, e, s, c, m, f, g.popSize);*/


    // ---------------------using GeneticAlgorithm class---------------------
    /*std::string solution = "well hello there";
    Generator g(solution.length(), 0);
    Evaluator e(solution, &g);
    GenericGenetics::Selector::Rank<std::string> s(100);
    Crossover c;
    Mutation m(&g);
    GenericGenetics::Criterion::Mark f(static_cast<float>(solution.length()));

    GenericGenetics::GeneticAlgorithm<
        std::string, Generator*, Evaluator*,
        GenericGenetics::Selector::Rank<std::string>*, Crossover*, Mutation*,
        GenericGenetics::Criterion::Mark*>
        algo(&g, &e, &s, &c, &m, &f);
    std::string result = algo.run(1'000);*/

    // ---------------------using GeneticAlgorithm class with specialization---------------------
    std::string solution = "well hello there";
    Generator g(solution.length(), 0);
    Evaluator e(solution, &g);
    GenericGenetics::Selector::Tournament<std::string> s(100, 10);
    Crossover c;
    Mutation m(&g);

    GenericGenetics::GeneticAlgorithm<
        std::string, Generator*, Evaluator*,
        GenericGenetics::Selector::Tournament<std::string>*, Crossover*, Mutation*,
        GenericGenetics::Criterion::Iterations*>
        algo(1'000, &g, &e, &s, &c, &m);
    std::string result = algo.run(1'000);

    std::cout << result << std::endl;

    return 0;
}
