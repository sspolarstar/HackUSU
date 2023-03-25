#include "headers/player.hpp"
#include "headers/mapManager.hpp"
#include "headers/collision.hpp"

Player::Player(float x, float y, sf::Vector2f size){
    this->position.setPosition({x,y});
    this->body.setFillColor(sf::Color(0,255,0));
    this->body.setSize(size);
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
	//Player animations
	sf::Vector2u walkRight(1, 5);
	sf::Vector2u walkUp(17, 21);
	sf::Vector2u walkDown(10, 12);
	sf::Vector2u holdStill(6, 8);
	//player movements
	//sf::Vector2f movement(0.0f, 0.0f);
	Position movement;
	movement.x = 0;
	movement.y = 0;
	
	sf::Vector2u rowLocator;
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		if (collision_direction.wall[LEFT]) {
		
		}
		else {
			movement.x -= speed * deltaTime;
			if (collision_direction.nextArea[LEFT]) {
				movement.x = movement.x / 3;
			}
			rowLocator = walkRight; //actually left!
		}
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		if (collision_direction.wall[RIGHT]) {}
		else {
			movement.x += speed * deltaTime;
			if (collision_direction.nextArea[RIGHT]) {
				movement.x = movement.x / 3;
			}
			rowLocator = walkRight;
		}		
	}
	if (movement.x == 0) {
		//row = 0;
		rowLocator = holdStill;
	}
	else {
		//let's rewrite this later. but I don't think we use this much.
		facesRight = movement.x > 0.0f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		if (collision_direction.wall[UP]) {}
		else {
			movement.y -= speed * deltaTime;
			rowLocator = walkUp;
		}
		if (collision_direction.nextArea[UP]) {
			movement.y = movement.y / 3;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		if (collision_direction.wall[DOWN]) {
		}
		else {
			movement.y += speed * deltaTime;
			rowLocator = walkDown;
		}
		if (collision_direction.nextArea[DOWN]) {
			movement.y = movement.y / 3;
		}
	}
	//end player movements
	//animation.Update(row, rowLocator, deltaTime, facesRight);
	//body.setTextureRect(animation.uvRect);

    this->move(movement);

}   

void Player::move(Position pos){
    this->position.setPosition(this->position + pos);
    this->body.setPosition(body.getPosition().x + pos.x, body.getPosition().y + pos.y);
	std::cout << body.getPosition().x << ", " << body.getPosition().y << std::endl;
}

void Player::draw(sf::RenderWindow &window){
    window.draw(body);
}

Position Player::getPosition(){
    return{this->body.getPosition().x, this->body.getPosition().y};
}