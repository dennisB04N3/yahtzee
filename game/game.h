#pragma once
#include"SFML/Window.hpp"
#include"SFML/Graphics.hpp"
#include"displaymanager.h"
#include"textfield.h"
#include"board.h"
#include"pointcard.h"
#include"playerscore.h"
#include"player.h"
#include<string>

/* Game Class controlling the fundamental game mechanics including game loop.
 * The method start() (called from main.cpp) contains the game loop which handles the events,
 * updates the game, calls the displaymanager to render and checks the roll count.
 * The main functionability for the user is to click objects on the screen, therefore the
 * checkTarget() function serves centralized purpose in this game.
 * Each element that can be clicked has boundaries which are tested with the mousePosition
 * on click. The function only checks the objects of the active player and therefore can
 * only transform public objects and the objects of the active player, but not the objects
 * of the inactive player.
 * Additionally there is the checkConfirmation() method which is called instead of the
 * checkTarget() method IFF the confirmationwindow handled by the displaymanager is visible,
 * so that the active player is excluded from every other choice to make than a confirmation.
 * The Event is not activated directly by an event, but rather by an event (mouseclick), which led
 * to the writing of the sum 0 to a field, therefore causing the confirmationwindow to pop up.
 *
 * Method update() updates the Dice Texture and ends the round if the points are written.
 */
class Game
{
private:
    //private attributes for the game
    DisplayManager* displaymanager;
    Board* board;
    Pointcard* pointcard;
    Player* player1;
    Player* player2;
    Player* activePlayer;
    //printing the amount of rolls and name of the active player
    Textfield* rollCountField;
    Textfield* activePlayerText;
    //attribute to check if the rollButton is swapped (locked)
    bool rollButtonSwapped { 0 };
    //attribute to check if the points in the current round are written
    bool pointsWritten { 0 };
    //rollcount initializes with 0
    int rollCount { 0 };
    //mouseposition initializes with 0,0
    sf::Vector2i mousePosition { 0, 0 };
    //attribute-buffer used for confirmation of writing a 0
    int buffer_index { 0 };
    std::vector<Button*>* buffer_scorefields;

public:
    //empty default constructor
    Game(){};
    //used c'tor taking the players names and the resource path to graphics, fonts, etc
    Game(const std::string player1, const std::string player2, const std::string res_path);
    //d'tor deleting dynamically allocated objects
    ~Game();

    //main game loop
    void start();
    //method to update textures and to end the round if points are written
    void update();
    //method checks for targets on clickEvent: Dices, RollButton, active players upper and lower section
    void checkTarget();
    //method checks for current amount of rolls to handle game functionality (locks rollButton, rolls at 0)
    void checkRollCount();
    //method to end the current round: rollCount(0), swapActivePlayer, unlocksRollButton
    void roundEnd();
    //method to secure the zero'ing out of a scorefield, gets activated if sum of dices is 0
    void checkConfirmation();
    //method to present the winner
    void winnerCheck();
    void checkWinner();

    //setter
    void swapActivePlayer();
    void writeActivePlayer();
    inline void updateMousePosition(){ this->mousePosition = sf::Mouse::getPosition(*this->displaymanager->getWindow()); }
};
