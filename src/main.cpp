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
    float stairTime = 0.0f;

    sf::Clock clock;
    sf::RectangleShape timerBackground;
    sf::Text textLabel;
    sf::Text timerText;
    sf::Font font;    
    ///////////////////////CLASSES
    sf::RenderWindow window(sf::VideoMode(500, 500), "Graduation");
    sf::View view(sf::FloatRect(0, 0, 500, 500));
   
    // stair enemies
    std::vector<Enemy> stair_guys(10);
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1,135);
    auto get_st_x = std::bind ( distribution, generator );

    sf::Texture sqlTexture;
    sqlTexture.loadFromFile("assets/img/squrrills.png");
    Squirrel sql(1600, 2900, sf::Vector2f(CELL_SIZE,CELL_SIZE), 120, sqlTexture, {4,3});    

    sf::Texture playerTexture;
    playerTexture.loadFromFile("assets/img/purpShirt.png");
    Player player(0.0,0.0, sf::Vector2f(CELL_SIZE,CELL_SIZE*2), playerTexture, {4,3});
    
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

        // std::cout<<player.getPosition().x << " " << player.getPosition().y <<std::endl;
        
        timerBackground.setPosition({player.getPosition().x - 248, player.getPosition().y - 248});
        timerText.setPosition({player.getPosition().x - 240, player.getPosition().y - 248});
        window.setView(view);
        window.clear();
        
        mapManager.drawMap(window);
        player.update(deltaTime, mapManager);
        player.draw(window);

        if(!player.gotSql){
            sql.update(deltaTime, player, 200, mapManager);
        }
        else {
            //you beat the squirl.
            if(!sql.seenDefeat)
                sql.defeat(font, window, {player.getPosition().x - 248, player.getPosition().y + 200});
        }
        sql.draw(window);

        // Handle stairs segments
        Position player_pos = player.getPosition();
        // check if they are in the stairs area
        if ((player_pos.x > 430) && (player_pos.x < 600)) {
            // begin to increment and update the stair counter
            stairTime += deltaTime;

            // if they are in the stairs area, check if they are in stage
            // one
            if ((player_pos.y > 2250)) {
                // if the stairTime is greater than 2 then
                // add a new person on the stairs and reset the timer
                // std::cout << stairTime << std::endl;
                if ((stairTime > 0.5) && (stair_guys.size() < 70)) {

                    // set this guys starting position
                    stair_guys.push_back(Enemy((450 + (float)get_st_x()), 2250,
                        sf::Vector2f(CELL_SIZE,CELL_SIZE*2), 80));
                    
                    // reset the stair time
                    stairTime = 0.0;
                }

                // render all of these enemies
                for (auto &stair_guy : stair_guys) {
                    // delete guys who are below screen
                    if (stair_guy.getPosition().y > (player.getPosition().y + 300) &&
                    stair_guy.getPosition().y > 3300) {
                        stair_guy.setPosition({stair_guy.getPosition().x, 2250});
                    }
                    stair_guy.move_in_dir(deltaTime, {0,1});
                    stair_guy.draw(window);
                }
            } else {
                stair_guys.clear();
            }

        }
        // else empty all the players on the stairs and set the stairtime
        // to 0
        else {
            stair_guys.clear();
            stairTime = 0.0;
        }

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