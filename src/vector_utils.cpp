#include "headers/vector_utils.hpp"

// gets magnitude of a vector
float v2util::magnitude_of(sf::Vector2f vec) {
    return sqrt(vec.x * vec.x + vec.y * vec.y);
}

// normalizes a vector
sf::Vector2f v2util::normalize(sf::Vector2f vec) {
    float mag = v2util::magnitude_of(vec);
    return sf::Vector2f((vec.x/mag), (vec.y/mag));
}