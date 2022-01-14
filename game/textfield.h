#pragma once
#include"SFML/Graphics.hpp"
#include<iostream>

/*Simple textfield class that holds necessary information to print a text to screen.*/
class Textfield
{
private:
    //holds the string
    sf::Text text;
    //needs a font
    sf::Font font;

public:
    //empty default constructor
    Textfield(){};
    /*used constructor.
     * @param:
        - position : sets position on screen
        - res_path : filepath to font
     */
    Textfield(const sf::Vector2f position, const std::string res_path);
    //empty d'tor
    ~Textfield(){};

    //sets string new and needs to build font new each time
    void writeText(const std::string input);
    //get the text
    inline sf::Text& getText() { return this->text; }
};
