#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Map {
public:
    Map();

    std::vector<std::array<sf::Vertex, 2>> buildLines();
    float getMaxX() const;
    float getMinX() const;
    float getMaxY() const;
    float getMinY() const;

private:
    std::vector<sf::Vector2f> points;
};
