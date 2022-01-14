#pragma once
#include"SFML/Graphics.hpp"
#include"dicetextures.h"
#include<iostream>

/* The Dice Class holds all information it needs to function as a dice.
 * Through the sprite it can function like a Button. If clicked it
 * is selected or deselected and therefore changing the texture.
 *
 * The Dicetexture class holds the textures which adresses are pointed to
 * if selected or not. This mechanism is working through a binding between
 * the current value and the index of the vectors thats holding the texture.
 *
 * .*/
class Dice
{
private:
    //attributes
    sf::Sprite sprite;
    DiceTextures dicetextures;

    int value;
    bool selected;
public:
    //empty default constructor
    Dice(){};
    //used c'tor, sets texture, value, selected and position
    Dice(const sf::Vector2f position, const std::string res_path);
    //empty d'tor
    ~Dice(){};

    //sets texture by if selected or not, with its value - 1 for index at vector
    void setTexture();
    //public method to change its bool value
    void swapSelected();
    //checks if click is inside sprite's bounds
    bool isClicked(sf::Vector2i mousePosition);

    //getter
    inline bool isSelected() const { return this->selected; }
    inline int getValue() const { return this->value; }
    inline sf::Sprite& getSprite() { return this->sprite; }
    //setter
    inline void setValue(const int value) { this->value = value; }
};
