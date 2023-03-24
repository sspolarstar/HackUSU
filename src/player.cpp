#include "headers/player.hpp"


Player::Player(float x, float y, sf::Vector2f size){
    this->position.setPosition({x,y});
    this->body.setFillColor(sf::Color(0,255,0));
    this->body.setSize(size);
}   

void Player::setPosition(float x, float y){
    this->position.setPosition(x,y);
    this->body.setPosition({x,y});
}
void Player::setPosition(Position pos){
    this->position.setPosition(pos);
    this->body.setPosition({pos.x, pos.y});
}

void Player::update(float deltaTime){
    //to move, check the keys
    float x = 0;
    float y = 0;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        x = this->speed * -deltaTime;
        //move left
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        x = this->speed * deltaTime;
        //move right
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        y = this->speed * -deltaTime;
        //move up
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        y = this->speed * +deltaTime;
        //move Down
    }
    this->move({x,y});

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