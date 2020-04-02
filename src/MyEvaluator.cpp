#include "MyEvaluator.hpp"
#include <cmath>

float MyEvaluator::operator()(std::string& s) const {
    float val = 0.0;
    std::string solution = "thibaut est un sacrer fdp";


    static const std::string alphanum = "abcdefghijklmnopqrstuvwxyz ";

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == solution[i])
            val += 1.0;
        else {
            int id = alphanum.find(s[i]);
            int id2 = alphanum.find(solution[i]);
            int v = alphanum.substr(id, id2 - id).length()+1;
            val += 0.9 - (v / (alphanum.length() - 1));
        }
        
    }

    return val;
}