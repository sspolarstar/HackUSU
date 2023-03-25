#pragma once

#include <SFML/Graphics.hpp>
#include "global.hpp"
#include "player.hpp"

class Animation {
	public:
		Animation();
        Animation(sf::Texture& texture, sf::Vector2u imageCount, float switchTime );
        void update(int row, sf::Vector2u rowLocater, float deltaTime, bool facesRight);
        sf::IntRect uvRect;
        
    private:
        float switchTime;
        float totalTime;

        sf::Vector2u imageCount;
        sf::Vector2u currentImage;
};