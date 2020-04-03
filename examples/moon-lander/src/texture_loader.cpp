#include <vector>

#include "texture_loader.hpp"

TextureLoader::TextureLoader() {
    std::vector<std::string> texturePaths = {};

    texturePaths.push_back("lander.png");
    texturePaths.push_back("landerthrust1.png");
    texturePaths.push_back("landerthrust2.png");

    for (const std::string& path : texturePaths) {
        std::string fileName = path.substr(0, path.find_last_of('.'));
        this->textures[fileName] = sf::Texture();
        this->textures[fileName].setSmooth(true);
        this->textures[fileName].loadFromFile("resources/" + path);
    }
}

const sf::Texture* TextureLoader::get(const std::string& name) const {
    return &this->textures.at(name);
}
