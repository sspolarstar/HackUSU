#include "headers/enemy.hpp"
#include "headers/mapManager.hpp"
#include "headers/collision.hpp"

/*
default constructor

takes x and y position, a Vector2f size (how many cells are used, see
    main.cpp for details), and speed.
*/
Enemy::Enemy(float x, float y, sf::Vector2f size, float speed) {
    this->position.setPosition(x, y);
    this->body.setPosition({x, y});
    // this->texture = texture;
    this->speed = speed;

    // default color is white. When player gets too close bad guy turns
    // red
    this->body.setFillColor(sf::Color(255,255,255));
    this->body.setSize(size);
}

// Adds pos to the current position
void Enemy::move(Position pos) {
    this->position.setPosition(this->position + pos);
    this->body.setPosition(body.getPosition().x + pos.x, body.getPosition().y + pos.y);
}

// updates an enemy. currently only updates position
// and only moves back and forth in the x direction
void Enemy::update(float deltaTime) {
    
    this->position.x += deltaTime * this->speed;
    this->body.setPosition(this->position.x, this->position.y);

    if (this->position.x > 100) {
        speed = speed * -1;
    }
    else if (this->position.x < 0) {
        speed = speed * -1;
    }
}

// updates an enemy to target a player. Takes a player reference,
// a trigger radius, and the timestep. When player is within the given
// radius, the enemy will move toward the player.
void Enemy::update(float deltaTime, Player &target,
        float radius, MapManager &mapRef) {
    
    // get the direction toward the target
    sf::Vector2f direction(target.getPosition().x - this->position.x,
        target.getPosition().y - this->position.y);

    // get the magnitude of the direction toward the player (sqrt(a^2 + b^2))
    float mag = sqrt(direction.x * direction.x + direction.y * direction.y);
    
    // calculate the collision
    Collided collision_direction = map_collision(this->position, mapRef);

    // if the player is within the radius
    if (mag < radius) {
        // then set the bad guy to be red
        this->body.setFillColor(sf::Color(255,0,10));

        // normalize the direction vector
        direction.x = direction.x/mag;
        direction.y = direction.y/mag;

        // move away from the player
        float deltaX = deltaTime * this->speed * direction.x;
        float deltaY = deltaTime * this->speed * direction.y;

         // check collision errors
        if ((deltaX < 0 && collision_direction.wall[LEFT]) ||
            (deltaX > 0 && collision_direction.wall[RIGHT])) {
                deltaX = 0.0;
        }
            

        if ((deltaY < 0 && collision_direction.wall[UP])||
            (deltaY > 0 && collision_direction.wall[DOWN])) {
                deltaY = 0.0;
        }
        
        this->position.x += deltaX;
        this->position.y += deltaY;
        this->body.setPosition(this->position.x, this->position.y);
    }
    // else if the player is not close enough then set the color to white
    else {
        this->body.setFillColor(sf::Color(255,255,255));
    }
    
}

void Enemy::draw(sf::RenderWindow &window) {
    window.draw(this->body);
    // std::cout << "Position is " << this->position.x << " " << this->position.y << std::endl;
}