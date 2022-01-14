#include "winnerwindow.h"

WinnerWindow::WinnerWindow(const std::string res_path)
{
    this->shape.setSize(sf::Vector2f(400, 140));
    this->shape.setPosition(250,140);
    this->shape.setFillColor(sf::Color::White);
    this->shape.setOutlineThickness(4);
    this->shape.setOutlineColor(sf::Color::Black);

    this->winnerText = Textfield(sf::Vector2f(300,150), res_path);
    this->winnerText.getText().setFillColor(sf::Color::Black);

    this->b_check.getShape().setSize(sf::Vector2f(50,50));
    this->b_check.getShape().setPosition(425,200);
    if(!this->texture_b_check.loadFromFile(res_path + "res/true.png"))
    {
        std::cout << "check button of winnerWindow not found!" << std::endl;
        std::exit(-1);
    }
    this->b_check.getShape().setTexture(&this->texture_b_check);
}

void WinnerWindow::setWinnerText(const std::string playername, const int points)
{
    this->winnerText.writeText(playername + " is the WINNER with " + std::to_string(points) +  " points!!!");
}

bool WinnerWindow::checkClicked(const sf::Vector2i mp)
{
    return this->b_check.isClicked(mp);
}
