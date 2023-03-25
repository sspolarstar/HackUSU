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
   
    // stair enemies
    std::vector<Enemy> stair_guys(10);
    Enemy tracker1, tracker2;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> stage_1(1,135);
    std::uniform_int_distribution<int> stage_2(60,100);
    auto get_st_x = std::bind ( stage_1, generator );
    auto get_st_s = std::bind ( stage_2, generator );

    sf::Texture sqlTexture;
    sqlTexture.loadFromFile("assets/img/squrrills.png");
    Squirrel sql(1582.61, 3005.69, sf::Vector2f(CELL_SIZE,CELL_SIZE), 120, sqlTexture, {4,3});    

    sf::Texture playerTexture;
    playerTexture.loadFromFile("assets/img/purpShirt.png");
    Player player(0.0,0.0, sf::Vector2f(CELL_SIZE,CELL_SIZE*2), playerTexture, {4,3});
    
    sf::Texture riddlerTexture;
    riddlerTexture.loadFromFile("assets/img/riddlerman.png");
    sf::RectangleShape riddlerBody;
    riddlerBody.setPosition({1969.0, 3013.26});
    riddlerBody.setSize({CELL_SIZE, CELL_SIZE*2});
    riddlerBody.setTexture(&riddlerTexture);

    sf::Texture speaker;
    speaker.loadFromFile("assets/img/browngirl.png");
    sf::RectangleShape speakerBody;
    speakerBody.setPosition({ 2930.76, 3244.76 });
    speakerBody.setSize({ CELL_SIZE, CELL_SIZE * 2 });
    speakerBody.setTexture(&speaker);
    speakerBody.setTextureRect({ (int)speaker.getSize().x, 0,  -1*CELL_SIZE,  2*CELL_SIZE });

    sf::Texture curious;
    curious.loadFromFile("assets/img/brownhair.png");
    sf::RectangleShape curiousBody;
    curiousBody.setPosition({ 2376.03, 3244.5 });
    curiousBody.setSize({ CELL_SIZE, CELL_SIZE * 2 });
    curiousBody.setTexture(&curious);

    sf::Texture squirelman;
    squirelman.loadFromFile("assets/img/blackman.png");
    sf::RectangleShape squirelmanBody;
    squirelmanBody.setPosition({ 2778.78, 3185.44 });
    squirelmanBody.setSize({ CELL_SIZE, CELL_SIZE * 2 });
    squirelmanBody.setTexture(&squirelman);

    sf::Texture squirelman1;
    squirelman1.loadFromFile("assets/img/blackman.png");
    sf::RectangleShape squirelman1Body;
    squirelman1Body.setPosition({ 1520.46, 3265.21 });
    squirelman1Body.setSize({ CELL_SIZE, CELL_SIZE * 2 });
    squirelman1Body.setTexture(&squirelman1);

    sf::Texture lady;
    lady.loadFromFile("assets/img/blondie.png");
    sf::RectangleShape ladyBody;
    ladyBody.setPosition({ 915.261, 3342.05 });
    ladyBody.setSize({ CELL_SIZE, CELL_SIZE * 2 });
    ladyBody.setTexture(&lady);

    sf::Texture lady1;
    lady1.loadFromFile("assets/img/blondie.png");
    sf::RectangleShape lady1Body;
    lady1Body.setPosition({ 2847.59, 3264.25 });
    lady1Body.setSize({ CELL_SIZE, CELL_SIZE * 2 });
    lady1Body.setTexture(&lady1);

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

        // std::cout<<player.getPosition().x << " " << player.getPosition().y <<std::endl;
        
        timerBackground.setPosition({player.getPosition().x - 248, player.getPosition().y - 248});
        timerText.setPosition({player.getPosition().x - 240, player.getPosition().y - 248});
        window.setView(view);
        window.clear();
        
        mapManager.drawMap(window);
        if(!player.updateFlag){
            player.update(deltaTime, mapManager);
        }
        player.draw(window);

        if(!player.gotSql){
            sql.update(deltaTime, player, 200, mapManager);
        }
        else {
            //you beat the squirl.
            if(!sql.seenDefeat)
                sql.defeat(font, window, {player.getPosition().x - 248, player.getPosition().y });
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
            if ((player_pos.y > 2360)) {
                // if the stairTime is greater than 2 then
                // add a new person on the stairs and reset the timer
                // std::cout << stairTime << std::endl;
                if ((stairTime > 0.5) && (stair_guys.size() < 70)) {

                    // set this guys starting position
                    stair_guys.push_back(Enemy((450 + (float)get_st_x()), 2360,
                        sf::Vector2f(CELL_SIZE,CELL_SIZE*2), 80));
                    
                    // reset the stair time
                    stairTime = 0.0;
                }

                // render all of these enemies
                for (auto &stair_guy : stair_guys) {
                    // delete guys who are below screen
                    if (stair_guy.getPosition().y > (player.getPosition().y + 300) &&
                    stair_guy.getPosition().y > 3300) {
                        stair_guy.setPosition({stair_guy.getPosition().x, 2360});
                    }
                    stair_guy.move_in_dir(deltaTime, {0,1});
                    stair_guy.draw(window);
                }

                // collision detection
                for (auto &stair_guy : stair_guys) {
                    // check distance between each stair_guy and the player
                    sf::Vector2f guy_center(stair_guy.getPosition().x + 8, stair_guy.getPosition().y + 16);
                    sf::Vector2f player_center(player.getPosition().x + 8, player.getPosition().y + 16);

                    // get the distance between the two
                    auto distance = v2util::magnitude_of((guy_center-player_center));

                    // if the distance is less than 17 (about one cell size) then send them back to the last stair
                    if (distance <= 17.0) {
                        // do some kind of send back
                        player.send_back_down_stairs(3300);
                        break;
                    }
                }
            } else if ((player_pos.y < 2360) && (player_pos.y > 2250)) {
                stair_guys.clear();
            } 
            // check if they are in stage 2
            else if (player_pos.y > 1400) {

                // add more people to the stairs, and randomize their velocity
                if ((stairTime > 0.5) && (stair_guys.size() < 80)) {
                    // get the spawn height
                    float spawn_height = (player.getPosition().y - 500) > 1400 ? (player.getPosition().y - 500) : 1400;

                    // set this guys starting position
                    stair_guys.push_back(Enemy((450 + (float)get_st_x()), 1400,
                        sf::Vector2f(CELL_SIZE,CELL_SIZE*2), (float)get_st_s()));
                    
                    // reset the stair time
                    stairTime = 0.0;
                }

                // render all of these enemies
                for (auto &stair_guy : stair_guys) {
                    // delete guys who are below screen
                    if (stair_guy.getPosition().y > (player.getPosition().y + 300) &&
                    stair_guy.getPosition().y > 2360) {
                        stair_guy.setPosition({stair_guy.getPosition().x, 1400});
                    }
                    stair_guy.move_in_dir(deltaTime, {0,1});
                    stair_guy.draw(window);
                }
            } else if ((player_pos.y < 1400) && (player_pos.y > 1200)) {
                stair_guys.clear();
                tracker1 = Enemy(440, 1310, sf::Vector2f(CELL_SIZE,CELL_SIZE*2), 90);
                tracker2 = Enemy(590, 1310, sf::Vector2f(CELL_SIZE,CELL_SIZE*2), 90);
            } else if (player_pos.y > 400) {

                // add more people to the stairs, and randomize their velocity
                if ((stairTime > 0.5) && (stair_guys.size() < 80)) {
                    // get the spawn height
                    float spawn_height = (player.getPosition().y - 300) > 400 ? (player.getPosition().y - 300) : 400;

                    // set this guys starting position
                    stair_guys.push_back(Enemy((450 + (float)get_st_x()), spawn_height,
                        sf::Vector2f(CELL_SIZE,CELL_SIZE*2), (float)get_st_s()));
                    
                    // reset the stair time
                    stairTime = 0.0;
                }

                // render all of these enemies
                for (auto &stair_guy : stair_guys) {
                    // delete guys who are below screen
                    if (stair_guy.getPosition().y > (player.getPosition().y + 300) &&
                    stair_guy.getPosition().y > 1500) {
                        stair_guy.setPosition({stair_guy.getPosition().x, 400});
                    }
                    stair_guy.move_in_dir(deltaTime, {0,1});
                    stair_guy.draw(window);
                }

                // update the tracker players
                tracker1.update(deltaTime, player, 200, mapManager);
                tracker2.update(deltaTime, player, 200, mapManager);
                tracker1.draw(window);
                tracker2.draw(window);
            } else {
                stair_guys.clear();
                tracker1.setPosition({440, 1210});
            }

        }
        // else empty all the players on the stairs and set the stairtime
        // to 0
        else {
            stair_guys.clear();
            stairTime = 0.0;
        }
        window.draw(riddlerBody);
        

        
        //switch statement for the different dialogs and actions
        //playerPosition.setPosition(floor(player.getPosition().x / 10), floor(player.getPosition().y/10));
        if(player.readyForInput){
            // player.getInput(font, window, {player.getPosition().x - 248, player.getPosition().y -200 });
        }
        p_y = floor(player.getPosition().y/10);
        p_x = floor(player.getPosition().x / 10);
        switch(p_y){
            case 289:
                if(p_x < 204 && p_x > 200){
                    if(!player.gotRiddler){
                        player.riddlerScene(font, window, {player.getPosition().x  - 248, player.getPosition().y -200});
                    }
                }
                break;
            default:
                break;   

        }
        window.draw(speakerBody);
        window.draw(curiousBody);
        window.draw(squirelmanBody);
        window.draw(squirelman1Body);
        window.draw(ladyBody);
        window.draw(lady1Body);

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