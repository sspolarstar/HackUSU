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

        // movement functions
        void move(Position pos);
        void send_back_down_stairs(float level);

        Position getPosition();
        void reduceTimeRemaing(float newTime){this->Time_Remaining = this->Time_Remaining - newTime;}
        float getTimeRemaing(){return this->Time_Remaining;}
        void setTimeRemaining(float newTime){this->Time_Remaining = newTime;}
        void riddlerScene(sf::Font &font,sf::RenderWindow& window, Position pos);
        void introScene(sf::Font &font, sf::RenderWindow& window);
        void introControls(sf::Font &font, sf::RenderWindow& window, Position pos);
        void introInstructions(sf::Font &font, sf::RenderWindow& window, Position pos);
        void getInput(sf::Font &font, sf::RenderWindow& window, Position pos);
    public:
        bool seenIntro = false;
        bool hasText = 1;
        bool gotSql = false;
        bool gotRiddler = false;
        bool updateFlag = false;
        bool seenIntroControls = false;
        bool seenIntroDirections = false;
        bool readyForInput = false;
        Animation animation;

        // movement lock for when travelling when doing stairs
        bool can_move_normally = true;
        float stair_level = 3360.0;

    private:
        float Time_Remaining = 15*60;
        float speed = 100;
        bool facesRight = false;
        Position position;
        sf::RectangleShape body;
};