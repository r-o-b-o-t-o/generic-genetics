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

    static int getWeightedRandomItem(const std::vector<float>& weights);

private:
    static std::mt19937 rng;
};

} // namespace GenericGenetics
