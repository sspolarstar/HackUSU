#include "headers/Animation.hpp"

Animation::Animation() {

}
Animation::Animation(sf::Texture& texture, sf::Vector2u imageCount, float switchTime){
    uvRect.width = texture.getSize().x/imageCount.x;
    uvRect.height = texture.getSize().y / imageCount.y;
    this->switchTime = switchTime;
    currentImage.x = 0;
    totalTime = 0.0f;
}

void Animation::update(int row, sf::Vector2u rowLocater, float deltaTime, bool facesRight){
    currentImage.y = row;
    totalTime += deltaTime;
    if (totalTime > this->switchTime) {
        totalTime = 0.0f;
        this->currentImage.x++;
        if (this->currentImage.x > this->imageCount.x) {
            this->currentImage.x = 0;
        }
        uvRect.top = currentImage.y * uvRect.height;
        if (facesRight) {
            uvRect.left = (currentImage.x + rowLocater.x) * uvRect.width;
            uvRect.width = abs(uvRect.width);
        }
        else {
            uvRect.left - (currentImage.x + rowLocater.x + 1) * abs(uvRect.width);
            uvRect.width = -abs(uvRect.width);
        }
    }
}
