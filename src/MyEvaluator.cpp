#include "MyEvaluator.hpp"
#include "MyGenerator.hpp"

MyEvaluator::MyEvaluator(const std::string& s) : solution(s) {}

float MyEvaluator::operator()(const std::string& s) const {
    float val = 0.0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == this->solution[i]) {
            val += 1.0;
        } else {
            int id = alphanum.find(s[i]);
            int id2 = alphanum.find(this->solution[i]);
            int v = alphanum.substr(id, id2 - id).length() + 1;
            val += 0.5f - (static_cast<float>(v) / static_cast<float>(alphanum.length() - 1));
        }
    }

    return val;
}
