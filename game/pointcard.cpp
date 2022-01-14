#include "pointcard.h"

Pointcard::Pointcard(const std::string res_path)
{
    this->shape.setPosition(518.0f, 0.0f);
    this->shape.setSize(sf::Vector2f(202.0f, 607.0f));
    if(!this->texture.loadFromFile(res_path + "res/card.png"))
    {
        std::cout << "Pointcard texture not found!" << std::endl;
        std::exit(-1);
    }
    this->shape.setTexture(&this->texture);
}
