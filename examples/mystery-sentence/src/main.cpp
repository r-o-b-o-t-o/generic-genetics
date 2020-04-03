#include "crossover.hpp"
#include "evaluator.hpp"
#include "generator.hpp"
#include "mutation.hpp"

#include "../../../include/criterion.hpp"
#include "../../../include/generate.hpp"
#include "../../../include/selectors.hpp"

int main() {
    std::string solution = "well hello there";
    Generator g(solution.length(), 1'000);
    Evaluator e(solution, &g);
    GenericGenetics::Selector::Rank<std::string> s(100);
    Crossover c;
    Mutation m(&g);
    GenericGenetics::Criterion::Mark f(static_cast<float>(solution.length()));

    std::string result =
        GenericGenetics::generate<std::string>(g, e, s, c, m, f, g.popSize);
    std::cout << result << std::endl;

    return 0;
}
