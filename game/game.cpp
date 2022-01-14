#include "game.h"
Game::Game(const std::string s_player1, const std::string s_player2, const std::string res_path)
{
    this->board = new Board(res_path);
    this->pointcard = new Pointcard(res_path);

    this->player1 = new Player(s_player1, sf::Vector2f(720.f, 0.f), res_path);
    this->player2 = new Player(s_player2, sf::Vector2f(810.f, 0.f), res_path);
    this->activePlayer = this->player1;

    this->rollCountField = new Textfield(sf::Vector2f(5,5), res_path);
    this->rollCountField->writeText("Rolls: " + std::to_string(this->rollCount));
    this->activePlayerText = new Textfield(sf::Vector2f(350,5), res_path);
    this->writeActivePlayer();

    this->buffer_scorefields = nullptr;
    this->displaymanager = new DisplayManager(this->board, this->pointcard, this->player1, this->player2, res_path);
}

Game::~Game()
{
    delete this->displaymanager;
    this->displaymanager = nullptr;
    delete this->board;
    this->board = nullptr;
    delete this->pointcard;
    this->pointcard = nullptr;
    this->activePlayer = nullptr;
    delete this->player2;
    this->player2 = nullptr;
    delete this->player1;
    this->player1 = nullptr;
    delete this->rollCountField;
    this->rollCountField = nullptr;
    delete this->activePlayerText;
    activePlayerText = nullptr;
}

void Game::start()
{
    //game loop
    while(this->displaymanager->getWindow()->isOpen())
    {
        sf::Event event;
        this->updateMousePosition();
        //handle events (mouseclick, closed)
        while(this->displaymanager->getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                this->displaymanager->getWindow()->close();
            }
            if (event.type == sf::Event::MouseButtonPressed && !this->displaymanager->getConfirmWindow()->isVisible())
            {
                this->checkTarget();
            }
            if (event.type == sf::Event::MouseButtonPressed && this->displaymanager->getConfirmWindow()->isVisible())
            {
                this->checkConfirmation();
            }
            if (event.type == sf::Event::MouseButtonPressed && this->displaymanager->getWinnerWindow()->isVisible())
            {
                this->winnerCheck();
            }
        }
        this->checkWinner();
        this->checkRollCount();
        this->update();
        this->displaymanager->render(this->rollCountField->getText(), this->activePlayerText->getText());
    }
}

void Game::checkTarget()
{
    //check mouseclick on all dices
    for (Dice* d : *this->board->getDices())
    {
        if(d->isClicked(this->mousePosition))
        {
            d->swapSelected();
        }
    }

    //check if "Roll Dice!" Button is clicked
    if (this->board->getRollButton()->isClicked(this->mousePosition))
    {
        if(this->rollCount < 3)
        {
            this->rollCount += 1;
            this->board->rollDices();
        }
    }


    //check if a Scorefield of active player has been clicked
    //upper Section
    for (int i = 0; i < 6; i++)
    {
        if (this->activePlayer->getPlayerscorecard()->getUpperSection()->at(i)->isClicked(this->mousePosition)
                && !(this->activePlayer->getPlayerscorecard()->getUpperSection()->at(i)->isLocked()))
        {
            int sum = this->activePlayer->getPlayerscorecard()->calculateUpperField(i, this->board->getDices());
            //confirmation mechanism activated if sum of dice's value is 0, index and scorefields are put into a buffer
            if(sum == 0)
            {
                this->displaymanager->getConfirmWindow()->setVisible(true);
                this->buffer_index = i;
                this->buffer_scorefields = this->activePlayer->getPlayerscorecard()->getUpperSection();
            }
            else
            {
                this->activePlayer->getPlayerscorecard()->getUpperSection()->at(i)->setButtonText(std::to_string(sum));
                this->pointsWritten = true;
            }
        }
    }
    //lower Section
    for (int i = 0; i < 7; i++)
    {
        if (this->activePlayer->getPlayerscorecard()->getLowerSection()->at(i)->isClicked(this->mousePosition)
                && !(this->activePlayer->getPlayerscorecard()->getLowerSection()->at(i)->isLocked()))
        {
            int sum = this->activePlayer->getPlayerscorecard()->calculateLowerField(i, this->board->getDices());
            //confirmation mechanism activated if sum of dice's value is 0, index and scorefields are put into a buffer
            if(sum == 0)
            {
                this->displaymanager->getConfirmWindow()->setVisible(true);
                this->buffer_index = i;
                this->buffer_scorefields = this->activePlayer->getPlayerscorecard()->getLowerSection();
            }
            else
            {
                this->activePlayer->getPlayerscorecard()->getLowerSection()->at(i)->setButtonText(std::to_string(sum));
                this->pointsWritten = true;
            }
        }
    }
}

void Game::update()
{
    this->rollCountField->writeText("Rolls: " + std::to_string(this->rollCount));
    this->board->updateDiceTextures();

    if(this->pointsWritten == true)
    {
        this->roundEnd();
    }
}

void Game::checkRollCount()
{
    if(this->rollCount == 0)
    {
        for (Dice* d : *this->board->getDices())
        {
            if(d->isSelected() == false)
            {
                d->swapSelected();
            }
        }
        this->board->rollDices();
        this->rollCount += 1;
    }
    else if(this->rollCount == 3)
    {
        this->board->getRollButton()->lockRollButton();
        this->rollButtonSwapped = true;
    }
}

void Game::swapActivePlayer()
{
    if (this->activePlayer->getName() == this->player1->getName())
    {
        this->activePlayer = this->player2;
    }
    else
    {
        this->activePlayer = this->player1;
    }
}

void Game::roundEnd()
{
    this->activePlayer->getPlayerscorecard()->updateUpperSection();
    this->activePlayer->getPlayerscorecard()->updateLowerSection();
    this->swapActivePlayer();
    this->writeActivePlayer();
    this->board->getRollButton()->unlockRollButton();
    this->rollCount = 0;
    this->pointsWritten = false;
}

void Game::writeActivePlayer()
{
    this->activePlayerText->writeText("Player: " + this->activePlayer->getName());
}

void Game::winnerCheck()
{

    if (this->displaymanager->getWinnerWindow()->checkClicked(this->mousePosition))
    {
        std::cout << "Thank you for playing! Since we don't want to get rectangular eyes we"
                  << " should take a walk now." << std::endl;
        std::exit(0);
    }
}

void Game::checkWinner()
{
    if(this->player1->getPlayerscorecard()->complete() && this->player2->getPlayerscorecard()->complete())
    {
        std::string player1str = this->player1->getPlayerscorecard()->getGrandTotal()->getText().getString();
        std::string player2str = this->player2->getPlayerscorecard()->getGrandTotal()->getText().getString();
        int pointsPlayer1 = std::atoi(player1str.c_str());
        int pointsPlayer2 = std::atoi(player2str.c_str());
        if (pointsPlayer1 > pointsPlayer2)
        {
            this->displaymanager->getWinnerWindow()->setWinnerText(this->player1->getName(), pointsPlayer1);
        }
        else
        {
            this->displaymanager->getWinnerWindow()->setWinnerText(this->player2->getName(), pointsPlayer2);

        }
        this->displaymanager->getWinnerWindow()->setVisible(true);
    }
}

void Game::checkConfirmation()
{
    if(this->displaymanager->getConfirmWindow()->trueClicked(this->mousePosition))
    {
        try
        {
            this->buffer_scorefields->at(buffer_index)->setButtonText("0");
            this->pointsWritten = true;
            this->displaymanager->getConfirmWindow()->setVisible(false);
            this->buffer_scorefields = nullptr;
        }
        catch (std::out_of_range)
        {
            std::cout << "buffer not filled, something went wrong..." << std::endl;
        }
    }
    if(this->displaymanager->getConfirmWindow()->falseClicked(this->mousePosition))
    {
        this->displaymanager->getConfirmWindow()->setVisible(false);
        this->buffer_scorefields = nullptr;
    }
}
