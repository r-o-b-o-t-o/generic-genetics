#include "bot_lander.hpp"

BotLander::BotLander(std::vector<std::pair<float, float>> commands)
    : Lander(TextureLoader(), sf::Vector2f(-200.0f, 200.0f), 1'000.0f),
      commands(commands) {}

void BotLander::setAngle(float angle) { this->angle = angle; }
void BotLander::setThrust(float thrust) { this->thrust = thrust; }