#pragma once
#include"SFML/Graphics.hpp"
#include"button.h"
#include"textfield.h"
/* Class to get confirmation from active user to write 0 to field or not
 */
class ConfirmationWindow
{
private:
    //visual attributes for the window
    sf::RectangleShape shape;
    //textures of buttons
    sf::Texture texture_b_true;
    sf::Texture texture_b_false;
    Textfield confirmationText;
    //Buttons included in the Confirmationwindow
    Button b_true;
    Button b_false;
    //bool that sets the window visible or not
    bool visible { 0 };

public:
    //empty default c'tor
    ConfirmationWindow(){};
    //used c'tor builing the shapes, textures (with path) and buttons
    ConfirmationWindow(const std::string res_path);
    //empty d'tor
    ~ConfirmationWindow(){};

    //getters
    inline bool isVisible() const { return this->visible; }
    bool trueClicked(const sf::Vector2i mp);
    bool falseClicked(const sf::Vector2i mp);
    //getters mainly for rendering
    inline sf::RectangleShape* getShape() { return &this->shape; }
    inline sf::Text* getConfirmationText() { return &this->confirmationText.getText(); }
    inline Button* getTrueButton() { return &this->b_true; }
    inline Button* getFalseButton() { return &this->b_false; }
    //setter for visibility
    inline void setVisible(const bool b) { this->visible = b; }

};
