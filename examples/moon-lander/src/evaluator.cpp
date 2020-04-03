#include "evaluator.hpp"
#include "generator.hpp"

Evaluator::Evaluator(Generator* generator)
    : generator(generator) {}

float Evaluator::operator()(const BotLander& indiv) const {
    float val = 0.0;
    BotLander s = indiv;
    /*float start = s.getTime();
    for (size_t i = 0; i < s.commands.size(); ++i) {
        s.setAngle(s.commands[i].first);
        s.setThrust(s.commands[i].second);
        float dt = s.getTime() - start;
        s.update(dt);
    }*/

    return val;
}
