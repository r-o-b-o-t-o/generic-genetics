#include <algorithm>

#include "map.hpp"

Map::Map() {
    // Shamelessly stolen from http://moonlander.seb.ly/ 😬
    this->points.emplace_back(0.5, 355.55);
    this->points.emplace_back(5.45, 355.55);
    this->points.emplace_back(6.45, 359.4);
    this->points.emplace_back(11.15, 359.4);
    this->points.emplace_back(12.1, 363.65);
    this->points.emplace_back(14.6, 363.65);
    this->points.emplace_back(15.95, 375.75);
    this->points.emplace_back(19.25, 388);
    this->points.emplace_back(19.25, 391.9);
    this->points.emplace_back(21.65, 400);
    this->points.emplace_back(28.85, 404.25);
    this->points.emplace_back(30.7, 412.4);
    this->points.emplace_back(33.05, 416.7);
    this->points.emplace_back(37.9, 420.5);
    this->points.emplace_back(42.7, 420.5);
    this->points.emplace_back(47.4, 416.65);
    this->points.emplace_back(51.75, 409.5);
    this->points.emplace_back(56.55, 404.25);
    this->points.emplace_back(61.3, 400);
    this->points.emplace_back(63.65, 396.15);
    this->points.emplace_back(68, 391.9);
    this->points.emplace_back(70.3, 388);
    this->points.emplace_back(75.1, 386.1);
    this->points.emplace_back(79.85, 379.95);
    this->points.emplace_back(84.7, 378.95);
    this->points.emplace_back(89.05, 375.65);
    this->points.emplace_back(93.75, 375.65);
    this->points.emplace_back(98.5, 376.55);
    this->points.emplace_back(103.2, 379.95);
    this->points.emplace_back(104.3, 383.8);
    this->points.emplace_back(107.55, 388);
    this->points.emplace_back(108.95, 391.9);
    this->points.emplace_back(112.4, 396.15);
    this->points.emplace_back(113.3, 400);
    this->points.emplace_back(117.1, 404.25);
    this->points.emplace_back(121.95, 404.25);
    this->points.emplace_back(125.3, 396.3);
    this->points.emplace_back(128.6, 394.2);
    this->points.emplace_back(132.45, 396.15);
    this->points.emplace_back(135.75, 399.9);
    this->points.emplace_back(138.15, 408.15);
    this->points.emplace_back(144.7, 412.4);
    this->points.emplace_back(146.3, 424.8);
    this->points.emplace_back(149.55, 436.65);
    this->points.emplace_back(149.55, 441.05);
    this->points.emplace_back(154.35, 444.85);
    this->points.emplace_back(163.45, 444.85);
    this->points.emplace_back(168.15, 441.05);
    this->points.emplace_back(172.95, 436.75);
    this->points.emplace_back(175.45, 432.9);
    this->points.emplace_back(179.7, 428.6);
    this->points.emplace_back(181.95, 424.8);
    this->points.emplace_back(186.7, 422.5);
    this->points.emplace_back(189.15, 412.4);
    this->points.emplace_back(191.55, 404.35);
    this->points.emplace_back(196.35, 402.4);
    this->points.emplace_back(200.7, 398.1);
    this->points.emplace_back(205.45, 391.9);
    this->points.emplace_back(210.15, 383.8);
    this->points.emplace_back(212.55, 375.75);
    this->points.emplace_back(216.85, 371.8);
    this->points.emplace_back(219.3, 367.55);
    this->points.emplace_back(220.65, 363.65);
    this->points.emplace_back(224, 359.4);
    this->points.emplace_back(228.8, 359.4);
    this->points.emplace_back(233.55, 355.55);
    this->points.emplace_back(237.85, 348.45);
    this->points.emplace_back(242.65, 343.2);
    this->points.emplace_back(245, 335.15);
    this->points.emplace_back(247.35, 322.8);
    this->points.emplace_back(247.3, 314.5);
    this->points.emplace_back(248.35, 306.55);
    this->points.emplace_back(252.2, 296.5);
    this->points.emplace_back(256.55, 294.55);
    this->points.emplace_back(257.95, 290.4);
    this->points.emplace_back(261.25, 285.95);
    this->points.emplace_back(265.95, 285.95);
    this->points.emplace_back(267, 290.25);
    this->points.emplace_back(271.75, 290.25);
    this->points.emplace_back(273.25, 294.55);
    this->points.emplace_back(275.2, 294.55);
    this->points.emplace_back(278.95, 296.5);
    this->points.emplace_back(282.25, 300.3);
    this->points.emplace_back(284.7, 308.45);
    this->points.emplace_back(291.85, 312.65);
    this->points.emplace_back(298.55, 330.8);
    this->points.emplace_back(303.25, 331.8);
    this->points.emplace_back(308, 335.05);
    this->points.emplace_back(309, 338.9);
    this->points.emplace_back(312.35, 343.2);
    this->points.emplace_back(313.8, 347.05);
    this->points.emplace_back(317.05, 351.4);
    this->points.emplace_back(321.9, 351.4);
    this->points.emplace_back(322.85, 363.8);
    this->points.emplace_back(326.6, 375.75);
    this->points.emplace_back(326.6, 379.95);
    this->points.emplace_back(330.9, 379.95);
    this->points.emplace_back(332.4, 383.8);
    this->points.emplace_back(335.8, 388);
    this->points.emplace_back(338.1, 396.15);
    this->points.emplace_back(340.45, 400.1);
    this->points.emplace_back(345.3, 404.25);
    this->points.emplace_back(346.25, 416.65);
    this->points.emplace_back(349.6, 428.7);
    this->points.emplace_back(349.6, 432.85);
    this->points.emplace_back(350.95, 436.75);
    this->points.emplace_back(354.3, 441.05);
    this->points.emplace_back(359, 441.05);
    this->points.emplace_back(361.4, 449.1);
    this->points.emplace_back(363.95, 453);
    this->points.emplace_back(368.2, 457.2);
    this->points.emplace_back(372.9, 461);
    this->points.emplace_back(410.2, 461);
    this->points.emplace_back(412.55, 449.1);
    this->points.emplace_back(417.4, 441.05);
    this->points.emplace_back(419.7, 432.9);
    this->points.emplace_back(422.05, 432.9);
    this->points.emplace_back(425.45, 424.8);
    this->points.emplace_back(428.8, 422.35);
    this->points.emplace_back(433.45, 416.65);
    this->points.emplace_back(438.25, 415.15);
    this->points.emplace_back(442.6, 412.4);
    this->points.emplace_back(447.4, 412.4);
    this->points.emplace_back(448.8, 416.65);
    this->points.emplace_back(454.55, 430.55);
    this->points.emplace_back(455.5, 434.8);
    this->points.emplace_back(459.25, 438.6);
    this->points.emplace_back(462.6, 440.9);
    this->points.emplace_back(466, 444.85);
    this->points.emplace_back(468.35, 452.9);
    this->points.emplace_back(475.55, 457.3);
    this->points.emplace_back(484.7, 457.3);
    this->points.emplace_back(494.7, 458.2);
    this->points.emplace_back(503.75, 461.1);
    this->points.emplace_back(522.2, 461.1);
    this->points.emplace_back(524.75, 453);
    this->points.emplace_back(527.1, 441.05);
    this->points.emplace_back(527.1, 432.9);
    this->points.emplace_back(531.9, 432.9);
    this->points.emplace_back(534.15, 424.8);
    this->points.emplace_back(538.6, 420.5);
    this->points.emplace_back(540.9, 416.65);
    this->points.emplace_back(542.35, 412.5);
    this->points.emplace_back(545.7, 408);
    this->points.emplace_back(550.45, 408);
    this->points.emplace_back(552.85, 398.1);
    this->points.emplace_back(554.75, 389.95);
    this->points.emplace_back(559.55, 388);
    this->points.emplace_back(564.35, 391.9);
    this->points.emplace_back(573.35, 391.9);
    this->points.emplace_back(578.1, 388);
    this->points.emplace_back(579.55, 379.95);
    this->points.emplace_back(582.9, 369.4);
    this->points.emplace_back(587.75, 367.55);
    this->points.emplace_back(588.65, 363.8);
    this->points.emplace_back(592.05, 359.5);
    this->points.emplace_back(596.85, 355.55);
}

std::vector<std::array<sf::Vertex, 2>> Map::buildLines() {
    std::vector<std::array<sf::Vertex, 2>> lines;
    size_t n = this->points.size();
    lines.reserve(n / 2);
    for (size_t i = 0; i < n - 1; ++i) {
        std::array<sf::Vertex, 2> line = {this->points[i], this->points[i + 1]};
        lines.push_back(std::move(line));
    }
    return lines;
}

float Map::getMaxX() const {
    float max = std::numeric_limits<float>::min();
    for (const sf::Vector2f& p : this->points) {
        if (p.x > max) {
            max = p.x;
        }
    }
    return max;
}

float Map::getMinX() const {
    float min = std::numeric_limits<float>::max();
    for (const sf::Vector2f& p : this->points) {
        if (p.x < min) {
            min = p.x;
        }
    }
    return min;
}

float Map::getMaxY() const {
    float max = std::numeric_limits<float>::min();
    for (const sf::Vector2f& p : this->points) {
        if (p.y > max) {
            max = p.y;
        }
    }
    return max;
}

float Map::getMinY() const {
    float min = std::numeric_limits<float>::max();
    for (const sf::Vector2f& p : this->points) {
        if (p.y < min) {
            min = p.y;
        }
    }
    return min;
}
