#pragma once
#include"SFML/Graphics.hpp"
#include<iostream>

/* Simple Class to print the Pointcard on Screen without any further functionality*/
class Pointcard
{
private:
    //attributes for visual representation
    sf::RectangleShape shape;
    sf::Texture texture;

public:
    //empty default constructor
    Pointcard(){};
    //used c'tor with the path to texture resource
    Pointcard(const std::string res_path);
    //empty d'tor
    ~Pointcard(){};

    //getter
    inline sf::RectangleShape& getShape() { return this->shape; }
};
