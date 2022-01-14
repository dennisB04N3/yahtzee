#pragma once
#include"winnerwindow.h"
#include"confirmationwindow.h"
#include"dice.h"
#include"textfield.h"
#include"board.h"
#include"pointcard.h"
#include"player.h"
#include"SFML/Window.hpp"
#include"SFML/Graphics.hpp"
#include<vector>

/* Class to manage all visual output
 */
class DisplayManager
{
private:

    sf::RenderWindow* window;
    ConfirmationWindow* confirmationWindow;
    WinnerWindow* winnerWindow;

    Board* board;
    Pointcard* pointcard;
    Player* player1;
    Player* player2;

public:

    DisplayManager();
    DisplayManager(Board*, Pointcard*, Player*, Player*, std::string res_path);
    ~DisplayManager();

    void render(sf::Text rollCount, sf::Text activePlayerName);

    inline sf::RenderWindow* getWindow() { return this->window; }
    inline ConfirmationWindow* getConfirmWindow() { return this->confirmationWindow; }
    inline WinnerWindow* getWinnerWindow() { return this->winnerWindow; }
};
