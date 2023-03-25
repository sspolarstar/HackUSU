#include "headers/mapManager.hpp"

MapManager::MapManager(){

}

void MapManager::setMap(Map& map){
    this->map = map;
}

void MapManager::drawMap(sf::RenderWindow & window){
    sf::RectangleShape cell;
    sf::Sprite sprite;
    sf::Texture testTexture;
    testTexture.loadFromFile("assets/img/texturemap.png");
    sprite.setTexture(testTexture);
    sprite.setTextureRect({ 0,0,16,16 });

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
                    sprite.setTextureRect({ 32, 32, 32, 32 });
                    sprite.setPosition({float(i*CELL_SIZE), float(j*CELL_SIZE)});
                    window.draw(sprite);
                    break;
                case Cell::stair:
                    sprite.setPosition({ float(i * CELL_SIZE), float(j * CELL_SIZE) });
                    sprite.setTextureRect({ 0, 0, 16, 16});
                    window.draw(sprite);
                    break;
                case Cell::grass:
                    sprite.setPosition({ float(i * CELL_SIZE), float(j * CELL_SIZE) });
                    sprite.setTextureRect({ 16, 0, 32, 16 });
                    window.draw(sprite);
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
                    break;
                case '0':
                    map.map[i][j] = Cell::stair;
                    break;
                case 'G':
                    map.map[i][j] = Cell::grass;
                    break;
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