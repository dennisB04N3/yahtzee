#include "button.h"

Button::Button( const sf::Vector2f size, const sf::Vector2f position, const std::string res_path) :
    Textfield(sf::Vector2f(position.x + 35 , position.y), res_path)
{
    this->shape.setPosition(position);
    this->shape.setSize(size);
    this->shape.setFillColor(sf::Color::White);
    this->locked = false;
}

bool Button::isClicked(const sf::Vector2i mousePosition)
{
    bool check = false;
    if(this->shape.getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y))
    {
        check = true;
    }
    return check;
}

void Button::setButtonText(const std::string input)
{
    if(!this->locked)
    {
        this->writeText(input);
        this->locked = true;
    }
}

void Button::unlockRollButton()
{
    this->shape.setFillColor(sf::Color::White);
    this->locked = false;
}

void Button::lockRollButton()
{
    this->shape.setFillColor(sf::Color::Red);
    this->locked = true;
}
