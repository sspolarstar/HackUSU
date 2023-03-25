#include "headers/player.hpp"
#include "headers/mapManager.hpp"
#include "headers/collision.hpp"

Player::Player(float x, float y, sf::Vector2f size, sf::Texture& texture, sf::Vector2u imageCount):
animation(texture, imageCount, 0.2f)
{

    this->position.setPosition({x,y});
    //this->body.setFillColor(sf::Color(0,255,0));
    this->body.setSize(size);
    this->body.setTexture(&texture);
}   

void Player::setPosition(float x, float y){
    this->position.setPosition({x,y});
    this->body.setPosition({x,y});
}
void Player::setPosition(Position pos){
    this->position.setPosition(pos);
    this->body.setPosition({pos.x, pos.y});
}

void Player::update(float deltaTime, MapManager& mapRef){
    //to move, check the keys
    float x = 0;
    float y = 0;
    Collided collision_direction = map_collision({this->getPosition()}, mapRef);
	Position movement;
	movement.x = 0;
	movement.y = 0;
	int row;
	sf::Vector2u rowLocator;
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)
	|| sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		if (collision_direction.wall[LEFT]) {
		
		}
		else {
			movement.x -= speed * deltaTime;
			if (collision_direction.nextArea[LEFT]) {
				movement.x = movement.x / 3;
			}
			row = 1; //actually left!
            facesRight = false;
		}
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)
	|| sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		if (collision_direction.wall[RIGHT]) {}
		else {
			movement.x += speed * deltaTime;
			if (collision_direction.nextArea[RIGHT]) {
				movement.x = movement.x / 3;
			}
			row = 1;
            facesRight = true;
		}		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)
	|| sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		if (collision_direction.wall[UP]) {}
		else {
			movement.y -= speed * deltaTime;
			row = 2;
		}
		if (collision_direction.nextArea[UP]) {
			movement.y = movement.y / 3;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)
	|| sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		if (collision_direction.wall[DOWN]) {
		}
		else {
			movement.y += speed * deltaTime;
			row = 0;
		}
		if (collision_direction.nextArea[DOWN]) {
			movement.y = movement.y / 3;
		}
	}
	//end player movements
    rowLocator = {0,3};
    if(movement.y == 0 && movement.x ==0){
        row = -1;
    }
	animation.update(row, deltaTime, facesRight);

	body.setTextureRect(animation.uvRect);

    this->move(movement);

}   

void Player::move(Position pos){
    this->position.setPosition(this->position + pos);
    this->body.setPosition(body.getPosition().x + pos.x, body.getPosition().y + pos.y);
}

void Player::draw(sf::RenderWindow &window){
    window.draw(body);
}

Position Player::getPosition(){
    return{this->body.getPosition().x, this->body.getPosition().y};
}