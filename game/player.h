#pragma once
#include"playerscore.h"
#include<iostream>

/* This is the Player class. It includes all necessary attributes and methods for the player
 * to calculate its points. So it has, like in the real world, its own Scorecard. This was
 * chosen by design to access the pointcard of the active player easier and manipulate only
 * the sheet of the active player, that is currently playing its round.
 */
class Player
{
private:
    //attributes
    std::string name;
    int points;
    Playerscore* playerscorecard;
public:
    //empty default c'tor
    Player(){};
    /* The actual c'tor thats used.
     * @parameters
       -name : name of the player
       -position : position of the scorecard
       -res_path : the path to texture of the scorecard
     * This c'tor builds the player with its name and the scorecard with the players name,
     * the position of the graphics on screen and the resource path to the graphic.
     * After initialization of the scorecard initializes the upper and lower section
     * and the scores of the scorecard, which are from class button.
     */
    Player(const std::string name, const sf::Vector2f position, const std::string res_path);
    //copy c'tor not necessary
    //d'tor destroying the dynamically scorecard, pointer to NULL
    ~Player();

    //getters
    inline std::string getName() const { return this->name ;}
    inline int getPoints() const { return this->points; }
    inline Playerscore* getPlayerscorecard() const { return this->playerscorecard; }

    //setters
    inline void setName(const std::string name) {this->name = name;}
    inline void setPoints(const int points) {this->points = points;}
};
