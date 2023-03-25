#pragma once

#include "global.hpp"
#include <SFML/Graphics.hpp>
#include "Animation.hpp"
class MapManager;
class Collision;

class MapManager;
class Collision;

class Player{
    public:
        Player(float x, float y, sf::Vector2f size, sf::Texture & texture, sf::Vector2u imageCount);
        void setPosition(Position pos);
        void setPosition(float x, float y);
        void update(float deltaTime, MapManager& mapRef);
        void draw(sf::RenderWindow &window);
        void move(Position pos);
        Position getPosition();
        void reduceTimeRemaing(float newTime){this->Time_Remaining = this->Time_Remaining - newTime;}
        float getTimeRemaing(){return this->Time_Remaining;}
        void setTimeRemaining(float newTime){this->Time_Remaining = newTime;}
    public:
        bool hasText = 1;
        bool gotSql = false;
        Animation animation;

    private:
        float Time_Remaining = 15*60;
        float speed = 100;
        bool facesRight = false;
        Position position;
        sf::RectangleShape body;
};