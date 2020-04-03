#pragma once

#include <random>
#include <vector>

namespace GenericGenetics {

class Random {
public:
    static int getInt(int min, int max) {
        std::uniform_int_distribution<int> dist(min, max);
        return dist(rng);
    }

    static float getFloat(float min, float max) {
        std::uniform_real_distribution<float> dist(min, max);
        return dist(rng);
    }

    static double getDouble(double min, double max) {
        std::uniform_real_distribution<double> dist(min, max);
        return dist(rng);
    }

    static bool getBool() { return getInt(0, 1) == 1; }

    template <typename T>
    static int getWeightedRandomItem(const std::vector<T>& weights) {
        std::discrete_distribution<int> distribution(weights.begin(),
                                                     weights.end());
        return distribution(rng);
    }

private:
    inline static std::mt19937 rng =
        std::mt19937(static_cast<unsigned int>(time(nullptr)));
};

} // namespace GenericGenetics
