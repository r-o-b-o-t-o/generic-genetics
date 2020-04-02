#include "MyEvaluator.hpp"
#include <cmath>

float MyEvaluator::operator()(const std::string& s) const {
    float val = 0.0;
    std::string solution = "thibautestunsacrerfdp";

    static const std::string alphanum = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == solution[i]) {
            val += 1.0;
        } else {
            int t = abs(s[i] - solution[i]);
            if (t < 2) {
                val += 0.5;
            } else if (t < 4) {
                val += 0.30;
            } else if (t < 6) {
                val += 0.1;
            }
        }
    }

    return val;
}
