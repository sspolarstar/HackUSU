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
    ///////////////////////CLASSES
    sf::RenderWindow window(sf::VideoMode(500, 500), "Test");
    sf::View view(sf::FloatRect(0, 0, 500, 500));
    Player player(0.0,0.0, sf::Vector2f(CELL_SIZE,CELL_SIZE*2));

    
    MapManager mapManager;
    mapManager.convertMap(mapSketch, player); //get mapSketch from assests/maps/maps.hpp

    shape.setPosition({100.0,100.0});
    shape.setOutlineThickness(1);
    shape.setOutlineColor(sf::Color(0.0,255,0.0));
    shape.setSize({25,25});
    shape.setRotation(12.0);

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
        view.reset(sf::FloatRect(player.getPosition().x - 250, player.getPosition().y - 250, 500, 500));

        window.setView(view);
        window.clear();
        window.draw(shape);
        mapManager.drawMap(window);
        player.update(deltaTime);
        player.draw(window);
        
        window.display();
    }

    return 0;
}