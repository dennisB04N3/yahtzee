#pragma once
#include"dice.h"
#include"button.h"
#include"SFML/System.hpp"
#include"SFML/Graphics.hpp"
#include<iostream>
#include<random>

/* Board class holds its texture and the dices. Also it has included the mechanic
 * to find a random number and the roll mechanics.
 */
class Board
{
private:
    //class-attributes for screen
    sf::RectangleShape shape;
    sf::Texture texture;
    //vector of dices which are positioned on the board
    std::vector<Dice*> dices;
    //button on the board
    Button rollButton;

    //class-attributes for generating a random number
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<int> dis;

    /*private class method which returns a random number of 6. No other functions
     * this types need to be implemented, therefor no utility class was needed
     */
    int getRandomOf6();

public:
    //empty default c'tor
    Board(){};
    //used c'tor thats building the graphics, no position since its fixed on screen
    Board(std::string res_path);
    //d'tor deleting Dices
    ~Board();

    //class method which iterates over dices and sets a new random num to the selected ones
    void rollDices();
    //public method thats sets the right texture of the dices
    void updateDiceTextures();

    //getters
    inline sf::RectangleShape& getShape() { return this->shape; }
    inline std::vector<Dice*>* getDices() { return &this->dices; }
    inline Button* getRollButton() { return &this->rollButton; }
};
