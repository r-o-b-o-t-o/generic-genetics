#include <SFML/Graphics.hpp>
#include <vector>

#include "map.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600),
                            "GenericGenetics - Moon Lander");
    sf::View view(sf::Vector2f(400.0f, 300.0f), sf::Vector2f(400.0f, 300.0f));
    window.setView(view);
    auto map = buildMap();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Escape || event.key.code == sf::Keyboard::Q) {
                    window.close();
                }
            }
        }

        window.clear(sf::Color::Black);

        for (const auto& line : map) {
            window.draw(line.data(), 2, sf::Lines);
        }

        window.display();
    }

    return 0;
}
