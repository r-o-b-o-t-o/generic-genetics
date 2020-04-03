#pragma once

#include <SFML/System.hpp>

#include "texture_loader.hpp"

class Lander {
public:
    Lander(const TextureLoader& textureLoader, const sf::Vector2f& pos);

    void update(float dt);
    const sf::Sprite& getSprite() const;
    const sf::Vector2f& getPos() const;
    float getThrust() const;
    float getAngle() const;
    sf::Vector2f getDirection() const;

    void addThrust();
    void turnLeft();
    void turnRight();

private:
    sf::Vector2f pos;
    sf::Vector2f velocity;
    sf::Vector2f accel;
    float angle;
    float thrust;
    bool isThrusting;

    sf::Sprite* sprite;
    sf::Sprite regularSprite;
    sf::Sprite thrust1Sprite;
    sf::Sprite thrust2Sprite;

    void setPos(const sf::Vector2f &pos);
    void updateSprite();
};
