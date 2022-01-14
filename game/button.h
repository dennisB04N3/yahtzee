#pragma once
#include"textfield.h"
#include"SFML/Graphics.hpp"
/* Button class which inherits from Textfield.
 * The common purpose of this class is to connect the Textfield
 * to the mechanics of a button. When the player made a choice where to use
 * its dice, the value must be written to a certain area where the user clicks.
 * Through the locking mechanism it can serve also as normal button.
 * Because its shape is seperated from its text it is possible to only print out
 * the text on screen.
 */
class Button : public Textfield
{
private:
    //attributes
    sf::RectangleShape shape;
    bool locked;

public:
    //empty default constructor
    Button():Textfield(){};
    /* Button constructor, builds the Button on position with size. Res_path
     * is for Textfield constructor which is called as well.
     */
    Button(const sf::Vector2f size, const sf::Vector2f position, const std::string res_path);
    ~Button(){};

    //\//mechanical methods
    //lock and unlock set also the color of the shape
    void lockRollButton();
    void unlockRollButton();
    //writes the text to the Textfield and locks the button without changing its color
    void setButtonText(const std::string input);
    bool isClicked(const sf::Vector2i mousePosition);
    //getter
    inline bool isLocked() const { return this->locked; }
    inline sf::RectangleShape& getShape() { return this->shape; }

};
