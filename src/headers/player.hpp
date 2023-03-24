#pragma once

#include <SFML/Graphics.hpp>
#include "global.hpp"

class Player{
    public:
        Player(float x, float y, sf::Vector2f size);
        void setPosition(Position pos);
        void setPosition(float x, float y);
        void update(float deltaTime);
        void draw(sf::RenderWindow &window);
        void move(Position pos);
        Position getPosition();
        bool hasText = 1;
    private:
        float speed = 100;
        Position position;
        sf::RectangleShape body;
        
        


};