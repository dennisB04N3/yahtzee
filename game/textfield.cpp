#include "textfield.h"

Textfield::Textfield(const sf::Vector2f position, const std::string res_path)
{
    if(!this->font.loadFromFile(res_path + "res/arial.ttf"))
    {
        std::cout << "font not found/standart path(main.cpp) may be wrong" << std::endl;
        std::exit(-1);
    }
    this->text.setPosition(position);
    this->text.setFillColor(sf::Color::Black);
    this->text.setCharacterSize(18);
}

void Textfield::writeText(const std::string input)
{
    this->text.setString(input);
    this->text.setFont(this->font);
}
