#include "headers/player.hpp"
#include "headers/mapManager.hpp"
#include "headers/collision.hpp"
#include "Script.hpp"
#include <unistd.h>
#include <thread>

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
	
	// Check if character is allowed to move normally (the only case they are not
	// is when they are being sent back down the stairs)
	if(this->can_move_normally) {
		// move the character based on keyboard input
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
	} // endif can_move_normally
	// else if player needs to go back down stairs, move them down the stairs
	else {
		movement.y = speed * 3 * deltaTime;
		movement.x = 0;
		row = 0;

		// if we have reached the level we needed to allow the player to move again
		if(this->body.getPosition().y > this->stair_level) {
			this->can_move_normally = true;
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
    textBox.setSize({480, 465});
    textBox.setOutlineColor(sf::Color::White);
    textBox.setOutlineThickness(2);
    textBox.setPosition({pos.x, pos.y - 45});
    window.draw(textBox);

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(20);
    text.setPosition({pos.x + 40, pos.y - 35});
    text.setString( mini_1_intro + "\npress Enter to Continue.");
    text.setFillColor(sf::Color(255,255,255,255));
    window.draw(text);
	window.display();
		while(1){
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
			break;
			}
		}
		for(int i = 0; i<1000; i++)std::cout<<" "<<std::endl;
	text.setString(riddle_1 + "\npress Enter to Continue.");
	text.setPosition({pos.x + 10, pos.y + 235});
	window.draw(text);
	window.display();
		while(1){
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
			break;
			}
		}
	using namespace std::chrono_literals;
	std::this_thread::sleep_for(200ms);
	
		readyForInput = true;
}



void Player::introScene(sf::Font& font, sf::RenderWindow& window){
	using namespace std::chrono_literals;

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

	std::this_thread::sleep_for(200ms);

}

void Player::introControls(sf::Font& font, sf::RenderWindow& window, Position pos){
	using namespace std::chrono_literals;

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

	std::this_thread::sleep_for(200ms);
}

void Player::send_back_down_stairs(float level) {
	this->can_move_normally = false;
	this->stair_level = level;
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

	using namespace std::chrono_literals;
	std::this_thread::sleep_for(200ms);

}