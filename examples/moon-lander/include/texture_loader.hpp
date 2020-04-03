#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class TextureLoader {
public:
    TextureLoader();
    const sf::Texture* get(const std::string& name) const;

private:
    std::map<std::string, sf::Texture> textures;
};
