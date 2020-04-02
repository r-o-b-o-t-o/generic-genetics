#pragma once

#include <random>
#include <vector>

namespace GenericGenetics {

class Random {
public:
    static int getInt(int min, int max);
    static float getFloat(float min, float max);
    static double getDouble(double min, double max);
    static bool getBool();

    template <typename T>
    static int getWeightedRandomItem(const std::vector<T>& weights) {
        std::discrete_distribution<int> distribution(weights.begin(), weights.end());
        return distribution(Random::rng);
    }

private:
    static std::mt19937 rng;
};

} // namespace GenericGenetics
