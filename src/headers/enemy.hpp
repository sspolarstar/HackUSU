#pragma once

#include "global.hpp"
#include "player.hpp"
#include "mapManager.hpp"
#include <string>
#include <cmath>

class Enemy{
    public:
        Enemy(float x, float y, sf::Vector2f size, float speed);
    
    public:
        // movement
        void setPosition(Position pos);
        void setPosition(float x, float y);
        void move(Position pos);

        // rendering and update functions
        void update(float deltaTime);
        void update(float deltaTime, Player &target, float radius);
        void draw(sf::RenderWindow &window);

        // debugging functionality
        bool showHitBox = false;

    private:
        // position variables
        Position position;
        float speed;

        // collision and textures
        sf::RectangleShape body;
        // sf::Texture& texture;

        // enemy information variables
        bool alive;
        int health;
        std::string identifier;
};