#pragma once

#include "global.hpp"
#include <cmath>

namespace v2util
{
    // gets magnitude of a vector
    float magnitude_of(sf::Vector2f vec);

    // normalizes a vector
    sf::Vector2f normalize(sf::Vector2f vec);
} // namespace v2util
