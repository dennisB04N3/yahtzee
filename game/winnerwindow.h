#pragma once
#include"SFML/Graphics.hpp"
#include"button.h"
#include"textfield.h"
class WinnerWindow
{
private:

    sf::RectangleShape shape;
    sf::Texture texture_b_check;
    Textfield winnerText;
    Button b_check;

    bool visible { 0 };
public:
    WinnerWindow(){};
    WinnerWindow(const std::string res_path);
    ~WinnerWindow(){};

    //setter
    void setWinnerText(const std::string playername, const int points);
    inline void setVisible(const bool b) { this->visible = b; }
    //getter
    bool checkClicked(const sf::Vector2i mp);
    inline bool isVisible() const { return this->visible; }
    inline sf::RectangleShape* getShape() { return &this->shape; }
    inline Button* getWinnerButton() { return &this->b_check; }
    inline sf::Text getWinnerText() { return this->winnerText.getText(); }


};

