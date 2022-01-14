#include "board.h"

Board::Board(std::string res_path) : dis(1, 6)
{
    //texture
    this->shape.setPosition(0.0f, 0.0f);
    this->shape.setSize(sf::Vector2f(518.0f, 607.0f));
    if(!this->texture.loadFromFile(res_path + "res/background.png"))
    {
        std::cout << "board texture not found!" << std::endl;
        std::exit(-1);
    }
    this->shape.setTexture(&this->texture);
    //init Dice
    this->dices.push_back(new Dice(sf::Vector2f(105.0f,120.0f), res_path));
    this->dices.push_back(new Dice(sf::Vector2f(105.0f,350.0f), res_path));
    this->dices.push_back(new Dice(sf::Vector2f(221.0f,235.5f), res_path));
    this->dices.push_back(new Dice(sf::Vector2f(337.0f,120.0f), res_path));
    this->dices.push_back(new Dice(sf::Vector2f(337.0f,350.0f), res_path));
    //set seed for random num generator
    this->gen.seed(rd());
    //init of rollButton
    this->rollButton = Button(sf::Vector2f(118,35), sf::Vector2f(200,15), res_path);
    this->rollButton.getShape().setOutlineThickness(3);
    this->rollButton.getShape().setOutlineColor(sf::Color::Black);
    this->rollButton.getText().setPosition(220, 20);
    this->rollButton.writeText("Roll Dice!");
}

Board::~Board()
{
    for (Dice* d : this->dices)
    {
        delete d;
        d = nullptr;
    }
}

void Board::rollDices()
{
    if(this->rollButton.isLocked() == false)
    {
        for(Dice* d : this->dices)
        {
            if (d->isSelected())
            {
                d->setValue(this->getRandomOf6());
                d->swapSelected();
            }
        }
    }
}

int Board::getRandomOf6()
{
    return dis(gen);
}

void Board::updateDiceTextures()
{
    for (Dice* d : this->dices)
    {
        d->setTexture();
    }
}
