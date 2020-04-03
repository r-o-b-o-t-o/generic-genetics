#include <cmath>

#include "lander.hpp"

Lander::Lander(const TextureLoader& textureLoader, const sf::Vector2f& pos)
    : pos(pos),
      angle(-90.0f),
      isThrusting(false),
      velocity(20.0f, 0.0f),
      accel(0.0f, 1.62f) {

    this->regularSprite.setTexture(*textureLoader.get("lander"));
    this->regularSprite.scale(sf::Vector2f(0.5f, 0.5f));
    sf::FloatRect bounds = this->regularSprite.getGlobalBounds();
    this->regularSprite.setOrigin(bounds.width / 2.0f, 0.0f);

    this->thrust1Sprite.setTexture(*textureLoader.get("landerthrust1"));
    this->thrust1Sprite.scale(sf::Vector2f(0.5f, 0.5f));
    bounds = this->thrust1Sprite.getGlobalBounds();
    this->thrust1Sprite.setOrigin(bounds.width / 2.0f, 0.0f);

    this->thrust2Sprite.setTexture(*textureLoader.get("landerthrust2"));
    this->thrust2Sprite.scale(sf::Vector2f(0.5f, 0.5f));
    bounds = this->thrust2Sprite.getGlobalBounds();
    this->thrust2Sprite.setOrigin(bounds.width / 2.0f, 0.0f);

    this->updateSprite();
}

float sign(float x) {
    if (x > 0.0f) {
        return 1.0f;
    } else if (x < 0.0f) {
        return -1.0f;
    }
    return 0.0f;
}

void Lander::update(float dt) {
    // http://lolengine.net/blog/2011/12/14/understanding-motion-in-games
    sf::Vector2f oldVel = this->velocity;
    this->velocity += this->accel * dt;
    this->velocity.x -= sign(this->velocity.x) * 1.5f * dt;
    sf::Vector2f pos = this->getPos() + (oldVel + this->velocity) * 0.5f * dt;
    this->setPos(pos);

    if (this->isThrusting) {
        this->isThrusting = false;
    } else {
        this->thrust = 0.0f;
    }
}

const sf::Sprite& Lander::getSprite() const { return *this->sprite; }

const sf::Vector2f& Lander::getPos() const { return this->pos; }

float Lander::getThrust() const { return this->thrust; }

float Lander::getAngle() const { return this->angle; }

sf::Vector2f Lander::getDirection() const {
    static const float deg2rad = M_PI * 2.0f / 360.0f;
    float x = std::cos((this->angle - 90.0f) * deg2rad);
    float y = std::sin((this->angle - 90.0f) * deg2rad);
    return sf::Vector2f(x, y);
}

void Lander::setPos(const sf::Vector2f& pos) {
    this->pos = pos;
    this->updateSprite();
}

void Lander::updateSprite() {
    if (this->thrust > 0.01f && this->thrust < 0.5f) {
        this->sprite = &this->thrust1Sprite;
    } else if (this->thrust >= 0.5f) {
        this->sprite = &this->thrust2Sprite;
    } else {
        this->sprite = &this->regularSprite;
    }

    this->sprite->setPosition(pos);
    this->sprite->setRotation(this->angle);
}

void Lander::addThrust() {
    this->thrust += 0.1f;
    this->thrust = std::min(this->thrust, 1.0f);
    static const float thrustPower = -0.1f;
    this->velocity -= this->getDirection() * thrustPower;
    this->isThrusting = true;
    this->updateSprite();
}

void Lander::turnLeft() {
    this->angle -= 2.0f;
    this->angle = std::max(this->angle, -90.0f);
    this->updateSprite();
}

void Lander::turnRight() {
    this->angle += 2.0f;
    this->angle = std::min(this->angle, 90.0f);
    this->updateSprite();
}
