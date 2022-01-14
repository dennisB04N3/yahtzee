#include "displaymanager.h"

DisplayManager::DisplayManager()
{
    /**
          / / /
       /        /  /     //    /
    /                 /         /  /
                    /
                   /                //
   /          /            /              /
   /            '/,        /               /
   /              'b      *
    /              '$    //                //
   /    /           $:   /:               /
 //      /  //      /  @/':        /   / /
              /     :@,@):   ,/':'   /
  /      /,         :@@*: //''      /   /
           '/o/    /:(@'/@*"'  /
   /  /       'bq,//:,@@*'   ,*      /  /
              ,p$q8,:@)'  /p*'      /
       /     '  / '@@Pp@@*'    /  /
        /  / //    Y7'.'     /  /
                  :@):.
                 .:@:'.
               .::(@:.      -Sam Blumenstein-/*/
}

DisplayManager::DisplayManager(Board* board, Pointcard* pointcard, Player* player1, Player* player2, std::string res_path)
{
    this->window = new sf::RenderWindow(sf::VideoMode(900, 607), "Kniffel2P", sf::Style::Close);
    this->window->setFramerateLimit(30);
    this->confirmationWindow = new ConfirmationWindow(res_path);
    this->winnerWindow = new WinnerWindow(res_path);
    this->board = board;
    this->pointcard = pointcard;
    this->player1 = player1;
    this->player2 = player2;
}

DisplayManager::~DisplayManager()
{
    delete window;
    window = nullptr;
    delete confirmationWindow;
    confirmationWindow = nullptr;
    delete winnerWindow;
    winnerWindow = nullptr;
    board = nullptr;
    pointcard = nullptr;
    player1 = nullptr;
    player2 = nullptr;
    //instances deleted otherwise
}

void DisplayManager::render(sf::Text rollCount, sf::Text activePlayerName)
{
    //clear screen
    this->window->clear();
    //basic elements of window
    this->window->draw(this->board->getShape());
    this->window->draw(this->pointcard->getShape());
    this->window->draw(this->player1->getPlayerscorecard()->getShape());
    this->window->draw(this->player2->getPlayerscorecard()->getShape());
    //dices
    for (Dice* d : *this->board->getDices())
    {
        this->window->draw(d->getSprite());
    }
    //Rollcount && ActivePlayerText && Playernames on playerscorecard
    this->window->draw(rollCount);
    this->window->draw(activePlayerName);
    this->window->draw(this->player1->getPlayerscorecard()->getTextfield()->getText());
    this->window->draw(this->player2->getPlayerscorecard()->getTextfield()->getText());
    //roll-button shape and text
    this->window->draw(this->board->getRollButton()->getShape());
    this->window->draw(this->board->getRollButton()->getText());
    //print the scorefield-Sections of the Playerscorecards that players are able to set by dicevalues...
    //...upper.
    for (Button* b : *this->player1->getPlayerscorecard()->getUpperSection())
    {
        this->window->draw(b->getText());
    }
    for (Button* b : *this->player2->getPlayerscorecard()->getUpperSection())
    {
        this->window->draw(b->getText());
    }
    //...lower.
    for (Button* b : *this->player1->getPlayerscorecard()->getLowerSection())
    {
        this->window->draw(b->getText());
    }
    for (Button* b : *this->player2->getPlayerscorecard()->getLowerSection())
    {
        this->window->draw(b->getText());
    }
    //print scores that are calculated with the scorefields...
    //...upper
    this->window->draw(this->player1->getPlayerscorecard()->getUpperScore()->getText());
    this->window->draw(this->player2->getPlayerscorecard()->getUpperScore()->getText());
    this->window->draw(this->player1->getPlayerscorecard()->getUpper35()->getText());
    this->window->draw(this->player2->getPlayerscorecard()->getUpper35()->getText());
    if (this->player1->getPlayerscorecard()->getUpperSectionComplete())
    {
        this->window->draw(this->player1->getPlayerscorecard()->getUpperTotal()->getText());
    }
    if (this->player2->getPlayerscorecard()->getUpperSectionComplete())
    {
        this->window->draw(this->player2->getPlayerscorecard()->getUpperTotal()->getText());
    }
    //...lower
    this->window->draw(this->player1->getPlayerscorecard()->getLowerScore()->getText());
    this->window->draw(this->player2->getPlayerscorecard()->getLowerScore()->getText());
    this->window->draw(this->player1->getPlayerscorecard()->getLowerUpper()->getText());
    this->window->draw(this->player2->getPlayerscorecard()->getLowerUpper()->getText());
    if (this->player1->getPlayerscorecard()->getLowerSectionComplete())
    {
        this->window->draw(this->player1->getPlayerscorecard()->getGrandTotal()->getText());
    }
    if (this->player2->getPlayerscorecard()->getLowerSectionComplete())
    {
        this->window->draw(this->player2->getPlayerscorecard()->getGrandTotal()->getText());
    }
    //print confirmation window, if it is set to visible
    if (this->confirmationWindow->isVisible())
    {
        this->window->draw(*this->confirmationWindow->getShape());
        this->window->draw(*this->confirmationWindow->getConfirmationText());
        this->window->draw((this->confirmationWindow->getTrueButton()->getShape()));
        this->window->draw((this->confirmationWindow->getFalseButton()->getShape()));
    }
    //print winnerWindow, if it is set to visible
    if (this->winnerWindow->isVisible())
    {
        this->window->draw(*this->winnerWindow->getShape());
        this->window->draw(this->winnerWindow->getWinnerButton()->getShape());
        this->window->draw(this->winnerWindow->getWinnerText());
    }
    //display
    this->window->display();
}
