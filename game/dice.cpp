#include "dice.h"

Dice::Dice(const sf::Vector2f position, const std::string res_path)
{
    this->dicetextures = DiceTextures(res_path);
    this->value = 1;
    this->selected = false;
    this->sprite.setTexture(*this->dicetextures.getTextureAt(this->value - 1));
    this->sprite.setPosition(position);
}

bool Dice::isClicked(sf::Vector2i mousePosition)
{
    bool check = false;
    if(this->sprite.getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y))
    {
        check = true;
    }
    return check;
}

void Dice::setTexture()
{
    if(this->selected)
    {
        this->sprite.setTexture(*this->dicetextures.getSelectedTextureAt(this->value - 1));
    }
    else
    {
        this->sprite.setTexture(*this->dicetextures.getTextureAt(this->value - 1));
    }
}

void Dice::swapSelected()
{
    if(this->selected == false)
    {
        this->selected = true;
    }
    else
    {
        this->selected = false;
    }
}
