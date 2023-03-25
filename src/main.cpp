#include <SFML/Graphics.hpp>
#include "headers/player.hpp"
#include "headers/global.hpp"
#include "headers/mapManager.hpp"
#include "headers/enemy.hpp"
#include "headers/collision.hpp"
#include "assets/maps/maps.hpp"


int main(){
    ////////////////////////VARIABLES
    float deltaTime = 0.0f;
    sf::Clock clock;
    sf::RectangleShape timerBackground;
    sf::Text textLabel;
    sf::Text timerText;
    sf::Font font;    
    ///////////////////////CLASSES
    sf::RenderWindow window(sf::VideoMode(500, 500), "Test");
    sf::View view(sf::FloatRect(0, 0, 500, 500));
    Player player(0.0,0.0, sf::Vector2f(CELL_SIZE,CELL_SIZE*2));
    Enemy big_bad(0.0,3.0, sf::Vector2f(CELL_SIZE,CELL_SIZE*2), 80);    
    
    MapManager mapManager;
    mapManager.convertMap(firstMap, player); //get mapSketch from assests/maps/maps.hpp

    /////////////////////functional asset rendering
    if (!font.loadFromFile("assets/fonts/sansation.ttf"))
        std::cout<<"no font loaded" << std::endl;
    timerText.setFont(font);
    timerText.setCharacterSize(20);
    timerText.setFillColor(sf::Color(255,255,255,255));
    timerText.setString("HELLO");

    timerBackground.setOutlineThickness(1);
    timerBackground.setOutlineColor(sf::Color(255,255,255));
    timerBackground.setSize({125,25});
    timerBackground.setFillColor(sf::Color(0,0,0,125));
    //timerBackground.setRotation(12.0);

    while (window.isOpen()){
        deltaTime = clock.restart().asSeconds();
        player.reduceTimeRemaing(deltaTime);
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            window.close();
        }
        
        view.reset(sf::FloatRect(float(player.getPosition().x - 250), float(player.getPosition().y - 250), 500, 500));
        timerBackground.setPosition({player.getPosition().x - 248, player.getPosition().y - 248});
        timerText.setPosition({player.getPosition().x - 240, player.getPosition().y - 248});
        window.setView(view);
        window.clear();
        
        mapManager.drawMap(window);
        player.update(deltaTime, mapManager);
        player.draw(window);

        big_bad.update(deltaTime, player, 200);
        big_bad.draw(window);

        if(player.hasText){
            window.draw(timerBackground);
            timerText.setString(std::to_string(player.getTimeRemaing()));
            window.draw(timerText);
        }
        //end the game if the timer runs out.
        if(player.getTimeRemaing() <= 0.0f){
                sf::RectangleShape endscreen;
                endscreen.setFillColor(sf::Color(0,0,0,125));
                endscreen.setPosition({float(player.getPosition().x - 250), float(player.getPosition().y - 250)});
                endscreen.setSize({550.0,550.0});
                sf::Text endscreenText;
                endscreenText.setPosition({float(player.getPosition().x - 125 - 16), float(player.getPosition().y)});
                endscreenText.setString("GAME OVER");
                endscreenText.setFont(font);
                endscreenText.setCharacterSize(50);
                endscreenText.setFillColor(sf::Color::White);

                window.draw(endscreen);
                window.draw(endscreenText);
                window.display();
            while(1){
                //end game;
                while (window.pollEvent(event)){
                    if (event.type == sf::Event::Closed)
                        window.close();
                        break;
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                    window.close(); 
                    break;
                }
            }
        }
        window.display();
    }

    return 0;
}