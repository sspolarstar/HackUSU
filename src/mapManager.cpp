#include "headers/mapManager.hpp"

MapManager::MapManager(){

}

void MapManager::setMap(Map& map){
    this->map = map;
}

void MapManager::drawMap(sf::RenderWindow & window){
    sf::RectangleShape cell;
    cell.setFillColor(sf::Color::Black);
    cell.setOutlineColor(sf::Color::White);
    cell.setOutlineThickness(2.0f);
    cell.setSize({float(CELL_SIZE), float(CELL_SIZE)});

    for(int i = 0; i < this->map.map.size(); i++){
        for(int j= 0; j< this->map.map[i].size(); j++){
            switch(this->map.map[j][i]){
                case Cell::empty:

                    break;
                case Cell::wall:
                    cell.setPosition({float(i*CELL_SIZE), float(j*CELL_SIZE)});
                    window.draw(cell);
                    break;
                default:
                    break;
            }
        }
    }
}


void MapManager::convertMap(std::array<std::string, MAX_MAP_HEIGHT>& mapSketch, Player& player){
    Map map;

    for(int i = 0; i < mapSketch.size(); i++){
        for(int j = 0; j < mapSketch[i].length(); j++){
            map.map[i][j] = Cell::empty;
            switch(mapSketch[i][j]){
                case ' ':
                    map.map[i][j] = Cell::empty;
                    break;
                case 'p':
                    player.setPosition({float(j*CELL_SIZE), float(i*CELL_SIZE)});
                    map.map[i][j] = Cell::wall;
                    
                    break;
                case '8':
                    map.map[i][j] = Cell::wall;
                default:
                    break;
            }
        }
    }

    this->setMap(map);
}


Map& MapManager::getMap(){
    return this->map;
}