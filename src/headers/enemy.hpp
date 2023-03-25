#pragma once

#include "global.hpp"
#include "player.hpp"
#include "mapManager.hpp"
#include "vector_utils.hpp"
#include <string>
#include <cmath>

class MapManager;

class Enemy{
    public:
        Enemy(float x, float y, sf::Vector2f size, float speed);
        Enemy();
    
    public:
        // movement
        void setPosition(Position pos) {
            this->position = pos;
            this->body.setPosition(pos.x, pos.y);
        }
        Position getPosition() {
            return this->position;
        }
        void setPosition(float x, float y);
        void move(Position pos);
        void move_from_a_to_b(float deltaTime, Position a, Position b);
        void move_in_dir(float deltaTime, sf::Vector2f dir);

        // rendering and update functions
        void update(float deltaTime);
        void update(float deltaTime, Player &target, float radius, MapManager &mapRef);
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