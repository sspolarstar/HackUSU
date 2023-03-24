#pragma once

#include <SFML/Graphics.hpp>
#include "global.hpp"
#include "player.hpp"

class MapManager{

    public:
        MapManager();
        Map& getMap();
        void drawMap(sf::RenderWindow &window);
        void setMap(Map&);
        void convertMap(std::array<std::string, MAX_MAP_HEIGHT> &i_map, Player& i_player);

    private:
        Map map;

};