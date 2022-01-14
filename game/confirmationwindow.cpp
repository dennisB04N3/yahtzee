#include "confirmationwindow.h"

ConfirmationWindow::ConfirmationWindow(const std::string res_path)
{
    this->shape.setSize(sf::Vector2f(280, 140));
    this->shape.setPosition(580, 140);
    this->shape.setFillColor(sf::Color(242, 157, 106));
    this->shape.setOutlineThickness(3);
    this->shape.setOutlineColor(sf::Color::Black);

    this->confirmationText = Textfield(sf::Vector2f(625, 150), res_path);
    this->confirmationText.getText().setFillColor(sf::Color::Black);
    this->confirmationText.writeText("   Write field with 0/\n      cross-out field?");

    this->b_true.getShape().setSize(sf::Vector2f(50, 50));
    this->b_true.getShape().setPosition(650, 210);
    if(!this->texture_b_true.loadFromFile(res_path + "res/true.png"))
    {
        std::cout << "true check button of confirmationWindow not found!" << std::endl;
        std::exit(-1);
    }


    this->b_false.getShape().setSize(sf::Vector2f(50, 50));
    this->b_false.getShape().setPosition(730, 210);
    if(!this->texture_b_false.loadFromFile(res_path + "res/false.png"))
    {
        std::cout << "false button of confirmationWindow not found!" << std::endl;
        std::exit(-1);
    }

    this->b_true.getShape().setTexture(&this->texture_b_true);
    this->b_false.getShape().setTexture(&this->texture_b_false);
}

bool ConfirmationWindow::trueClicked(const sf::Vector2i mp)
{
    return this->b_true.isClicked(mp);
}

bool ConfirmationWindow::falseClicked(const sf::Vector2i mp)
{
    return this->b_false.isClicked(mp);
}
