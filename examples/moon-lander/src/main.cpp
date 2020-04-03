#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <vector>

#include "lander.hpp"
#include "map.hpp"
#include "texture_loader.hpp"

bool cmp(const sf::Vector2f& lhs, const sf::Vector2f& rhs) {
    return lhs.x < rhs.x;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600),
                            "GenericGenetics - Moon Lander");
    window.setVerticalSyncEnabled(true);
    sf::Clock clock;
    TextureLoader textureLoader;
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(400.0f, 300.0f));
    view.zoom(1.0f);
    window.setView(view);

    bool humanControl = true;

    Map map;
    std::vector<std::array<sf::Vertex, 2>> mapLines = map.buildLines();
    size_t mapLinesN = mapLines.size();
    std::vector<std::array<sf::Vertex, 2>> movedMapLines;
    movedMapLines.reserve(2 * mapLinesN);
    for (int i = 0; i < 2; ++i) {
        for (const std::array<sf::Vertex, 2>& line : mapLines) {
            movedMapLines.push_back(line);
        }
    }
    float mapMin = map.getMinX();
    float mapMax = map.getMaxX();
    float mapSize = mapMax - mapMin;

    Lander lander(textureLoader, sf::Vector2f(-200.0f, 200.0f), 1'000.0f);
    sf::Vertex line[2];
    float mapScroll;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Escape ||
                    event.key.code == sf::Keyboard::Q) {
                    window.close();
                }
            }
        }

        sf::Time _dt = clock.restart();
        float dt = _dt.asSeconds();
        if (humanControl) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                lander.turnLeft();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                lander.turnRight();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                lander.addThrust();
            }
        }
        lander.update(dt);

        window.clear(sf::Color::Black);

        view.setCenter(lander.getPos() + sf::Vector2f(0.0f, 70.0f));
        window.setView(view);

        mapScroll = std::ceil(lander.getPos().x / mapSize);
        mapScroll -= 0.5f;
        for (int i = 0; i < 2; ++i) {
            for (size_t j = 0; j < mapLinesN; ++j) {
                int idx = i * mapLinesN + j;
                movedMapLines[idx][0] = mapLines[j][0];
                movedMapLines[idx][1] = mapLines[j][1];
                movedMapLines[idx][0].position.x +=
                    (-mapSize * i) + mapSize * mapScroll;
                movedMapLines[idx][1].position.x +=
                    (-mapSize * i) + mapSize * mapScroll;
                line[0] = movedMapLines[idx][0];
                line[1] = movedMapLines[idx][1];
                window.draw(line, 2, sf::Lines);
            }
        }

        window.draw(lander.getSprite());
        /*sf::CircleShape bounds(7.5f);
        bounds.setOrigin(bounds.getRadius(), 0.0f);
        bounds.setRotation(lander.getAngle());
        bounds.setOutlineColor(sf::Color::Red);
        bounds.setOutlineThickness(1.0f);
        bounds.setFillColor(sf::Color::Transparent);
        bounds.setPosition(lander.getPos());
        window.draw(bounds);*/

        window.display();
    }

    return 0;
}
