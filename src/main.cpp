#include <SFML/Graphics.hpp>
#include "headers/player.hpp"
#include "headers/global.hpp"
#include "headers/mapManager.hpp"
#include "assets/maps/maps.hpp"
int main()
{
    ////////////////////////VARIABLES
    float deltaTime = 0.0f;
    sf::Clock clock;
    sf::RectangleShape shape;
    sf::Text textLabel;
    sf::Text textValue;
    sf::Font font;    
    ///////////////////////CLASSES
    sf::RenderWindow window(sf::VideoMode(500, 500), "Test");
    sf::View view(sf::FloatRect(0, 0, 500, 500));
    Player player(0.0,0.0, sf::Vector2f(CELL_SIZE,CELL_SIZE*2));

    
    
    MapManager mapManager;
    mapManager.convertMap(mapSketch, player); //get mapSketch from assests/maps/maps.hpp

    /////////////////////functional asset rendering
    if (!font.loadFromFile("assets/fonts/sansation.ttf"))
        std::cout<<"no font loaded" << std::endl;
    textValue.setFont(font);
    textValue.setCharacterSize(20);
    textValue.setFillColor(sf::Color(255,255,255,255));
    textValue.setString("HELLO");

    shape.setOutlineThickness(1);
    shape.setOutlineColor(sf::Color(255,255,255));
    shape.setSize({125,25});
    shape.setFillColor(sf::Color(0,0,0,125));
    //shape.setRotation(12.0);

    while (window.isOpen()){
        deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            window.close();
        }
        view.reset(sf::FloatRect(float(player.getPosition().x - 250), float(player.getPosition().y - 250), 500, 500));
        shape.setPosition(float(player.getPosition().x - 248), float(player.getPosition().y - 248));
        textValue.setPosition({player.getPosition().x - 240, player.getPosition().y - 248});
        window.setView(view);
        window.clear();
        
        mapManager.drawMap(window);
        player.update(deltaTime);
        player.draw(window);
        if(player.hasText){
            window.draw(shape);
            window.draw(textValue);
        }
        
        window.display();
    }

    return 0;
}