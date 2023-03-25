#include <SFML/Graphics.hpp>
#include "headers/player.hpp"
#include "headers/global.hpp"
#include "headers/mapManager.hpp"
#include "headers/enemy.hpp"
#include "headers/collision.hpp"
#include "assets/maps/maps.hpp"
#include "headers/squirrel.hpp"


int main(){
    ////////////////////////VARIABLES
    float deltaTime = 0.0f;
    sf::Clock clock;

    int minute;
    int second;

    sf::RectangleShape timerBackground;
    sf::Text textLabel;
    sf::Text timerText;
    sf::Font font;    
    //player positions for later switch statement
    int p_x, p_y;
    ///////////////////////CLASSES
    sf::RenderWindow window(sf::VideoMode(500, 500), "Graduation");
    sf::View view(sf::FloatRect(0, 0, 500, 500));
   
    Enemy big_bad(0.0,3.0, sf::Vector2f(CELL_SIZE,CELL_SIZE*2), 80);

    sf::Texture sqlTexture;
    sqlTexture.loadFromFile("assets/img/squrrills.png");
    Squirrel sql(1600, 2900, sf::Vector2f(CELL_SIZE,CELL_SIZE), 120, sqlTexture, {4,3});    

    sf::Texture playerTexture;
    playerTexture.loadFromFile("assets/img/purpShirt.png");
    Player player(0.0,0.0, sf::Vector2f(CELL_SIZE,CELL_SIZE*2), playerTexture, {4,3});
    
    sf::Texture riddlerTexture;
    riddlerTexture.loadFromFile("assets/img/riddlerman.png");
    sf::RectangleShape riddlerBody;
    riddlerBody.setPosition({1969.0,2902.9});
    riddlerBody.setSize({CELL_SIZE, CELL_SIZE*2});
    riddlerBody.setTexture(&riddlerTexture);

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

        if(!player.seenIntro){
            player.introScene(font, window);
            clock.restart().asSeconds();
        } else if(!player.seenIntroControls){
            player.introControls(font, window, {player.getPosition().x - 250, player.getPosition().y - 250});
            clock.restart().asSeconds();
        } else if(!player.seenIntroDirections){
            player.introInstructions(font, window, {player.getPosition().x - 250, player.getPosition().y - 250});
            clock.restart().asSeconds();            
        }
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
        std::cout<<player.getPosition().x << " " << player.getPosition().y <<std::endl;
        timerBackground.setPosition({player.getPosition().x - 248, player.getPosition().y - 248});
        timerText.setPosition({player.getPosition().x - 240, player.getPosition().y - 248});
        window.setView(view);
        window.clear();
        
        mapManager.drawMap(window);
        if(!player.updateFlag){
            player.update(deltaTime, mapManager);
        }
        player.draw(window);

        big_bad.update(deltaTime, player, 200, mapManager);
        big_bad.draw(window);
        if(!player.gotSql){
            sql.update(deltaTime, player, 200, mapManager);
        }
        else {
            //you beat the squirl.
            if(!sql.seenDefeat)
                sql.defeat(font, window, {player.getPosition().x - 248, player.getPosition().y });
        }
        sql.draw(window);
        window.draw(riddlerBody);
        

        
        //switch statement for the different dialogs and actions
        //playerPosition.setPosition(floor(player.getPosition().x / 10), floor(player.getPosition().y/10));
        p_y = floor(player.getPosition().y/10);
        p_x = floor(player.getPosition().x / 10);
        switch(p_y){
            case 289:
                if(p_x < 204 && p_x > 200){
                    if(!player.gotRiddler){
                        player.riddlerScene(font, window, {player.getPosition().x  - 248, player.getPosition().y  + 200});
                    }
                }
                break;
            default:
                break;   

        }

        if(player.hasText){
            window.draw(timerBackground);
            minute = (int)player.getTimeRemaing() / 60;
            second = (int)player.getTimeRemaing() % 60;
            if (second >= 10) {
                timerText.setString(std::to_string(minute) + ":" + std::to_string(second));
            }
            else {
                timerText.setString(std::to_string(minute) + ":0" + std::to_string(second));
            }
            
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