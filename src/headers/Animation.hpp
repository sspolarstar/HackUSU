#pragma once

#include <SFML/Graphics.hpp>
#include "global.hpp"

class Animation {
	public:
        Animation(sf::Texture& texture, sf::Vector2u& imageCount, float switchTime );
        void update(int row,  float deltaTime, bool facesRight);
        sf::IntRect uvRect;
        
    private:
        float switchTime;
        float totalTime;

        sf::Vector2u imageCount;
        sf::Vector2u currentImage;
};