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
                    //sprite.setColor(sf::Color::Blue);
                    window.draw(sprite);
                    sprite.setColor(sf::Color(255,255,255,255));
                    break;
                case Cell::Left_rail:
                    sprite.setPosition({ float(i * CELL_SIZE), float(j * CELL_SIZE) });
                    sprite.setTextureRect({ 0, 16, 16, 32 });
                    window.draw(sprite);
                    break;
                case Cell::Right_rail:
                    sprite.setPosition({ float(i * CELL_SIZE), float(j * CELL_SIZE) });
                    sprite.setTextureRect({ 16, 16, 32, 32 });
                    window.draw(sprite);
                    break;
                case Cell::concrete:
                    sprite.setPosition({ float(i * CELL_SIZE), float(j * CELL_SIZE) });
                    sprite.setTextureRect({ 0, 32, 16, 48 });
                    window.draw(sprite);
                    break;
                case Cell::bush:
                    sprite.setPosition({ float(i * CELL_SIZE), float(j * CELL_SIZE) });
                    sprite.setTextureRect({ 16, 32, 32, 48 });
                    window.draw(sprite);
                    break;
                case Cell::flower:
                    sprite.setPosition({ float(i * CELL_SIZE), float(j * CELL_SIZE) });
                    sprite.setTextureRect({ 0, 48, 16, 64 });
                    window.draw(sprite);
                    break;
                case Cell::gravel:
                    sprite.setPosition({ float(i * CELL_SIZE), float(j * CELL_SIZE) });
                    sprite.setTextureRect({ 0, 64, 16, 80 });
                    window.draw(sprite);
                    break;
                case Cell::dirt:
                    sprite.setPosition({ float(i * CELL_SIZE), float(j * CELL_SIZE) });
                    sprite.setTextureRect({ 16, 48, 32, 64 });
                    window.draw(sprite);
                    break;
                case Cell::t1:
                    sprite.setPosition({ float(i * CELL_SIZE), float(j * CELL_SIZE) });
                    sprite.setTextureRect({ 32, 0, 48, 16 });
                    window.draw(sprite);
                    break;
                case Cell::t2:
                    sprite.setPosition({ float(i * CELL_SIZE), float(j * CELL_SIZE) });
                    sprite.setTextureRect({ 48, 0, 64, 16 });
                    window.draw(sprite);
                    break;
                case Cell::t3:
                    sprite.setPosition({ float(i * CELL_SIZE), float(j * CELL_SIZE) });
                    sprite.setTextureRect({ 64, 0, 80, 16 });
                    window.draw(sprite);
                    break;
                case Cell::t4:
                    sprite.setPosition({ float(i * CELL_SIZE), float(j * CELL_SIZE) });
                    sprite.setTextureRect({ 32, 16, 48, 32 });
                    window.draw(sprite);
                    break;
                case Cell::t5:
                    sprite.setPosition({ float(i * CELL_SIZE), float(j * CELL_SIZE) });
                    sprite.setTextureRect({ 48, 16, 64, 32 });
                    window.draw(sprite);
                    break;
                case Cell::t6:
                    sprite.setPosition({ float(i * CELL_SIZE), float(j * CELL_SIZE) });
                    sprite.setTextureRect({ 64, 16, 80, 32 });
                    window.draw(sprite);
                    break;
                case Cell::dirtbush:
                    sprite.setPosition({ float(i * CELL_SIZE), float(j * CELL_SIZE) });
                    sprite.setTextureRect({ 32, 32, 48, 48 });
                    window.draw(sprite);
                    break;
                case Cell::bench:
                    sprite.setPosition({ float(i * CELL_SIZE), float(j * CELL_SIZE) });
                    sprite.setTextureRect({ 48, 32, 64, 48 });
                    window.draw(sprite);
                    break;
                case Cell::podium:
                    sprite.setPosition({ float(i * CELL_SIZE), float(j * CELL_SIZE) });
                    sprite.setTextureRect({ 64, 32, 80, 48 });
                    window.draw(sprite);
                    break;
                case Cell::brick:
                    sprite.setPosition({ float(i * CELL_SIZE), float(j * CELL_SIZE) });
                    sprite.setTextureRect({ 32, 48, 48, 64 });
                    window.draw(sprite);
                    break;
                case Cell::window:
                    sprite.setPosition({ float(i * CELL_SIZE), float(j * CELL_SIZE) });
                    sprite.setTextureRect({ 48, 48, 64, 64 });
                    window.draw(sprite);
                    break;
                case Cell::sky:
                    sprite.setPosition({ float(i * CELL_SIZE), float(j * CELL_SIZE) });
                    sprite.setTextureRect({ 32, 64, 48, 80 });
                    window.draw(sprite);
                    break;
                case Cell::aggie:
                    sprite.setPosition({ float(i * CELL_SIZE), float(j * CELL_SIZE) });
                    sprite.setTextureRect({ 48, 64, 64, 80 });
                    window.draw(sprite);
                    break;
                case Cell::end:
                    sprite.setPosition({ float(i * CELL_SIZE), float(j * CELL_SIZE) });
                    sprite.setTextureRect({ 64, 48, 80, 64 });
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
                    map.map[i][j] = Cell::concrete;
                    
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
                case 'L':
                    map.map[i][j] = Cell::Left_rail;
                    break;
                case 'R':
                    map.map[i][j] = Cell::Right_rail;
                    break;
                case 'C':
                    map.map[i][j] = Cell::concrete;
                    break;
                case '*':
                    map.map[i][j] = Cell::flower;
                    break;
                case '#':
                    map.map[i][j] = Cell::bush;
                    break;
                case 'V':
                    map.map[i][j] = Cell::gravel;
                    break;
                case 'D':
                    map.map[i][j] = Cell::dirt;
                    break;
                case '1':
                    map.map[i][j] = Cell::t1;
                    break;
                case '2':
                    map.map[i][j] = Cell::t2;
                    break;
                case '3':
                    map.map[i][j] = Cell::t3;
                    break;
                case '4':
                    map.map[i][j] = Cell::t4;
                    break;
                case '5':
                    map.map[i][j] = Cell::t5;
                    break;
                case '6':
                    map.map[i][j] = Cell::t6;
                    break;
                case 'T':
                    map.map[i][j] = Cell::dirtbush;
                    break;
                case 'B':
                    map.map[i][j] = Cell::bench;
                    break;
                case 'P':
                    map.map[i][j] = Cell::podium;
                    break;
                case 'K':
                    map.map[i][j] = Cell::brick;
                    break;
                case 'W':
                    map.map[i][j] = Cell::window;
                    break;
                case 'S':
                    map.map[i][j] = Cell::sky;
                    break;
                case 'I':
                    map.map[i][j] = Cell::aggie;
                    break;
                case 'E':
                    map.map[i][j] = Cell::end;
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