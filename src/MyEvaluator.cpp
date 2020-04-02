#include "MyEvaluator.hpp"
#include "MyGenerator.hpp"
#include <cmath>

MyEvaluator::MyEvaluator(const std::string& s) : solution(s) {}

float MyEvaluator::operator()(const std::string& s) const {
    float val = 0.0;
    std::string solution = "Thibaut est un sacrer fdp, j ai jurer wola.";


    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == this->solution[i]) {
            val += 1.0;
        } else {
            int id = alphanum.find(s[i]);
            int id2 = alphanum.find(this->solution[i]);
            int v = alphanum.substr(id, id2 - id).length()+1;
            val += 0.99 - (v / (alphanum.length() - 1));
        }
    }

    return val;
}
