#include "headers/Animation.hpp"

Animation::Animation(sf::Texture& texture, sf::Vector2u& imageCount, float switchTime){
    uvRect.width = texture.getSize().x/imageCount.x;
    uvRect.height = (texture.getSize().y + 3) / (imageCount.y);
   
    std::cout<< uvRect.width << uvRect.height <<std::endl;
    this->switchTime = 0.1f;
    currentImage.x = 0;
    totalTime = 0.0f;
}

void Animation::update(int row, float deltaTime, bool facesRight){
    currentImage.y = row;
    totalTime += deltaTime;
    if (totalTime > this->switchTime) {
        totalTime -= this->switchTime;
        if(row != -1){
            uvRect.top = currentImage.y * uvRect.height;
            if (facesRight) {
                uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
                uvRect.width = -abs(uvRect.width);
            }
            else {
                uvRect.left = (currentImage.x) * uvRect.width;
                uvRect.width = abs(uvRect.width);
            }
            this->currentImage.x++;
            if (this->currentImage.x > 3) {
                this->currentImage.x = 0;
            }
        }
        else{
            currentImage.x = 2;
            if (facesRight) {
                uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
                uvRect.width = -abs(uvRect.width);
            }
            else {
                uvRect.left = (currentImage.x) * uvRect.width;
                uvRect.width = abs(uvRect.width);
            }
        }

    }
}
