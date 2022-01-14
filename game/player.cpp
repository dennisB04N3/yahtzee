#include "player.h"

Player::Player(const std::string name, const sf::Vector2f position, const std::string res_path)
{
    this->name = name;
    this->points = 0;
    this->playerscorecard = new Playerscore(position, name, res_path);
    this->playerscorecard->initUpperSection(res_path);
    this->playerscorecard->initLowerSection(res_path);
    this->playerscorecard->initScores(res_path);
    this->playerscorecard->updateUpperSection();
    this->playerscorecard->updateLowerSection();
}

Player::~Player()
{
    delete this->playerscorecard;
    this->playerscorecard = nullptr;
}
