#include "global.hpp"
#include "player.hpp"
#include "mapManager.hpp"

class Enemy{
    public:
        Enemy(Position pos, sf::Texture&, float speed);
        ~Enemy();
    
    public:
        bool showHitBox = false;


    private:
        Position position;
        sf::RectangleShape body;
        float speed;


};