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

Enemy::Enemy() {
    this->position.setPosition(0, 0);
    this->body.setPosition({0, 0});
    // this->texture = texture;
    this->speed = speed;

    // default color is white. When player gets too close bad guy turns
    // red
    this->body.setFillColor(sf::Color(255,255,255));
    this->body.setSize(sf::Vector2f(CELL_SIZE * 2, CELL_SIZE));
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

// move the enemy in a straight line, FOREVER HAHAHAHAHA
void Enemy::move_in_dir(float deltaTime, sf::Vector2f dir) {
    // get the magnitude of the direction toward the player (sqrt(a^2 + b^2))
    float mag = sqrt(dir.x * dir.x + dir.y * dir.y);

    // normalize the direction vector
    dir.y = dir.y/mag;
    dir.x = dir.x/mag;
        
    // move
    float deltaX = deltaTime * this->speed * dir.x;
    float deltaY = deltaTime * this->speed * dir.y;

    // update the position
    this->position.x += deltaX;
    this->position.y += deltaY;
    this->body.setPosition(this->position.x, this->position.y);
}

// move the enemy between two points
void Enemy::move_from_a_to_b(float deltaTime, Position a, Position b) {
    // when true enemy is moving toward a, else moving toward b
    static bool to_a = true;

    // get the direction from the enemy to the next point
    sf::Vector2f dir;
    if (to_a) {
        dir = {a.x-this->position.x, a.y-this->position.y};
    } else {
        dir = {b.x-this->position.x, b.y-this->position.y};
    }

    // check if we need to switch directions
    if (to_a && (v2util::magnitude_of(dir) < (2 * deltaTime * this->speed))) {
        to_a = !to_a;
    } else if (!to_a && (v2util::magnitude_of(dir) < (2 * deltaTime * this->speed))) {
        to_a = !to_a;
    }

    // normalize the direction from a to b (or vice versa)
    dir = v2util::normalize(dir);
        
    // move
    float deltaX = deltaTime * this->speed * dir.x;
    float deltaY = deltaTime * this->speed * dir.y;

    // update the position
    this->position.x += deltaX;
    this->position.y += deltaY;
    this->body.setPosition(this->position.x, this->position.y);   
    
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