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
        void riddlerScene(sf::Font &font,sf::RenderWindow& window, Position pos);
        void introScene(sf::Font &font, sf::RenderWindow& window);
        void introControls(sf::Font &font, sf::RenderWindow& window, Position pos);
        void introInstructions(sf::Font &font, sf::RenderWindow& window, Position pos);
        void getInput(sf::Font &font, sf::RenderWindow& window, Position pos);
        void riddleTwo(sf::Font &font, sf::RenderWindow& window, Position pos);
        void riddleThree(sf::Font &font, sf::RenderWindow& window, Position pos);
        void riddlerFinished(sf::Font &font, sf::RenderWindow& window, Position pos);
        void trapMisLead(sf::Font &font,sf::RenderWindow& window, Position pos);
        void meeting(sf::Font &font,sf::RenderWindow& window, Position pos);
        void halter(sf::Font &font,sf::RenderWindow& window, Position pos);
        void kickedOutOfGraduation(sf::Font &font, sf::RenderWindow& window, Position pos);
        void miniwarn(sf::Font &font, sf::RenderWindow& window, Position pos);
    public:
        bool seenIntro = false;
        bool hasText = 1;
        bool gotSql = false;
        bool gotRiddler = false;
        bool gotRiddlerFinished = false;
        bool updateFlag = false;
        bool seenIntroControls = false;
        bool seenIntroDirections = false;
        bool readyForInput = false;
        bool riddleOneCorrect = false;
        bool riddleTwoCorrect = false;
        bool riddleThreeCorrect = false;
        bool riddleTwoReady = false;
        bool riddleThreeReady = false;
        bool doneTrapMislead = false;
        bool doneMeeting = false;
        bool halterDone = false;
        bool miniwarn1 = false;
        Animation animation;

    private:
        float Time_Remaining = 15*60;
        float speed = 200;
        bool facesRight = false;
        Position position;
        sf::RectangleShape body;
};