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
    float mapMin = map.getMinX();
    float mapMax = map.getMaxX();
    float mapSize = mapMax - mapMin;

    Lander lander(textureLoader, sf::Vector2f(-200.0f, 200.0f));
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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            lander.turnLeft();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            lander.turnRight();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            lander.addThrust();
        }
        lander.update(dt);

        window.clear(sf::Color::Black);

        view.setCenter(lander.getPos() + sf::Vector2f(0.0f, 70.0f));
        window.setView(view);

        mapScroll = std::ceil(lander.getPos().x / mapSize);
        mapScroll -= 0.5f;
        for (const auto& l : mapLines) {
            line[0] = l[0];
            line[1] = l[1];
            line[0].position.x += -mapSize + mapSize * mapScroll;
            line[1].position.x += -mapSize + mapSize * mapScroll;
            window.draw(line, 2, sf::Lines);
        }
        for (const auto& l : mapLines) {
            line[0] = l[0];
            line[1] = l[1];
            line[0].position.x += mapSize * mapScroll;
            line[1].position.x += mapSize * mapScroll;
            window.draw(line, 2, sf::Lines);
        }

        window.draw(lander.getSprite());

        window.display();
    }

    return 0;
}
