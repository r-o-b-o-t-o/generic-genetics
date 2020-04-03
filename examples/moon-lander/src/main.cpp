#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <vector>

#include "lander.hpp"
#include "map.hpp"
#include "texture_loader.hpp"

#define CUTE_C2_IMPLEMENTATION
#include "cute_c2.h"

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

        sf::CircleShape bounds(7.5f);
        bounds.setOrigin(bounds.getRadius(), 0.0f);
        bounds.setRotation(lander.getAngle());
        bounds.setOutlineColor(sf::Color::Red);
        bounds.setOutlineThickness(1.0f);
        bounds.setFillColor(sf::Color::Transparent);
        bounds.setPosition(lander.getPos());
        c2Circle c2Bounds;
        c2Bounds.p.x = bounds.getPosition().x + bounds.getOrigin().x;
        c2Bounds.p.y = bounds.getPosition().y + bounds.getOrigin().y;
        c2Bounds.r = bounds.getRadius();

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

                c2Poly poly;
                poly.count = 4;
                poly.verts[0].x = line[0].position.x;
                poly.verts[0].y = line[0].position.y;
                poly.verts[1].x = line[1].position.x;
                poly.verts[1].y = line[1].position.y;
                poly.verts[2].x = line[0].position.x;
                ;
                poly.verts[2].y = 2000.0f;
                poly.verts[3].x = line[1].position.x;
                poly.verts[3].y = 2000.0f;
                int collision = c2CircletoPoly(c2Bounds, &poly, nullptr);
                if (collision == 1) {
                    // Collided
                    if (line[1].position.y - line[0].position.y > 0.01f) {
                        // If ground is not horizontal
                        std::cout << "rip\n";
                    }
                    if (!(lander.getAngle() >= -10 &&
                          lander.getAngle() <= 10)) {
                        // If lander is not vertical
                        std::cout << "rip\n";
                    }
                    float speed =
                        std::sqrt(std::pow(lander.getVelocity().x, 2) +
                                  std::pow(lander.getVelocity().y, 2));
                    if (speed >= 8.0f) {
                        // If lander lands too fast
                        std::cout << "rip\n";
                    }
                }
            }
        }

        window.draw(lander.getSprite());
        window.draw(bounds);

        window.display();
    }

    return 0;
}
