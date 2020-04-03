#include "evaluator.hpp"
#include "generator.hpp"

Evaluator::Evaluator(const std::string& s, Generator* generator)
    : solution(s), generator(generator) {}

float Evaluator::operator()(const std::string& s) const {
    float val = 0.0;
    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] == this->solution[i]) {
            val += 1.0;
        } else {
            int id = this->generator->alphanum.find(s[i]);
            int id2 = this->generator->alphanum.find(this->solution[i]);
            int v = this->generator->alphanum.substr(id, id2 - id).length() + 1;
            val += 0.5f -
                   (static_cast<float>(v) /
                    static_cast<float>(this->generator->alphanum.length() - 1));
        }
    }

    return val;
}
