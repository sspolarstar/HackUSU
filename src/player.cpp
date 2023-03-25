#include "headers/player.hpp"
#include "headers/mapManager.hpp"
#include "headers/collision.hpp"
#include "Script.hpp"
#include <unistd.h>
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
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
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
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
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


void Player::riddlerScene(sf::Font &font,sf::RenderWindow& window, Position pos){
	this->gotRiddler = true;
	this->updateFlag = true;
    sf::RectangleShape textBox;
    textBox.setFillColor(sf::Color(0,0,0,125));
    textBox.setSize({480, 65});
    textBox.setOutlineColor(sf::Color::White);
    textBox.setOutlineThickness(2);
    textBox.setPosition({pos.x, pos.y - 45});
    window.draw(textBox);

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(20);
    text.setPosition({pos.x + 10, pos.y - 35});
    text.setString(  "\npress Enter to Continue.");
    text.setFillColor(sf::Color(255,255,255,255));
    window.draw(text);

		while(1){
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
			break;
		}
	}
	this->updateFlag = false;
}



void Player::introScene(sf::Font& font, sf::RenderWindow& window){
	seenIntro = true;
	window.clear();
	sf::RectangleShape textBox;
    textBox.setFillColor(sf::Color(0,0,0,125));
    textBox.setSize({400, 400});
    textBox.setOutlineColor(sf::Color::White);
    textBox.setOutlineThickness(2);
    textBox.setPosition({50, 50});
    window.draw(textBox);

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(20);
    text.setPosition({65,65});
    text.setString(intro_story + "\npress Enter to Continue");
    text.setFillColor(sf::Color(255,255,255,255));
    window.draw(text);

	

	window.display();
	while(1){
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
			break;
		}
	}

	for(int i = 0; i<1000;i++) std::cout<<" " <<std::endl;;

}

void Player::introControls(sf::Font& font, sf::RenderWindow& window, Position pos){
	seenIntroControls = true;
	sf::RectangleShape textBox;
    textBox.setFillColor(sf::Color(0,0,0,175));
    textBox.setSize({400, 400});
    textBox.setOutlineColor(sf::Color::White);
    textBox.setOutlineThickness(2);
    textBox.setPosition({pos.x + 50, pos.y +50});
    window.draw(textBox);

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(20);
    text.setPosition({pos.x + 65, pos.y + 65});
    text.setString(intro_controls + "\npress Enter to Continue");
    text.setFillColor(sf::Color(255,255,255,255));
    window.draw(text);

	

	window.display();
	while(1){
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
			break;
		}
	}
	for(int i = 0; i<1000;i++) std::cout<<" " <<std::endl;;
}




void Player::introInstructions(sf::Font& font, sf::RenderWindow& window, Position pos){
	seenIntroDirections = true;
	sf::RectangleShape textBox;
    textBox.setFillColor(sf::Color(0,0,0,175));
    textBox.setSize({400, 400});
    textBox.setOutlineColor(sf::Color::White);
    textBox.setOutlineThickness(2);
    textBox.setPosition({pos.x + 50, pos.y +50});
    window.draw(textBox);

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(20);
    text.setPosition({pos.x + 65, pos.y + 65});
    text.setString(intro_directions + "\npress Enter to Continue");
    text.setFillColor(sf::Color(255,255,255,255));
    window.draw(text);

	

	window.display();
	while(1){
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
			break;
		}
	}

}