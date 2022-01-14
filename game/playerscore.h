#pragma once
#include"textfield.h"
#include"button.h"
#include"dice.h"
#include"SFML/Graphics.hpp"
#include"SFML/Window.hpp"
#include"SFML/System.hpp"
#include<vector>
#include<unordered_map>

/* Playerscore is the magical Card of the Player, which holds the values he has rolled.
 * It contains its visual parts like shape, texture and textfield for the name.
 *
 * But also it manages the values that needs to be stored and calculated which is the main part.
 *
 * By nature this sheet has a upper section and a lower section because the rules
 * to legitely write the sums of dice are different. Upper section focuses on the dice
 * itself, while the lower section concentrates on combination of pairs.
 *
 * Lower section is mainly solved through a map of vectors. The dice value is its key
 * and pushes the vector. Size of vector therefore represents the amount of the same keys,
 * which are the combinations. Those combinations are tested by relatively generic methods.
 *
 * Also boolean values are declared to define which scores should be written and which dont.
 * They also help the game Class to check for the end of game.
 */
class Playerscore
{
private:
    //attributes for visual representation
    sf::RectangleShape shape;
    sf::Texture texture;
    Textfield playerNameField;
    //Buttons for handling the Scores of the Player
    std::vector<Button*>* upperSection;
    std::vector<Button*>* lowerSection;
    Button *upperScore, *upper35, *upperTotal, *lowerScore, *lowerUpper, *grandTotal;
    //attributes for testing if parts or the sections are complete
    bool upperComplete, upperSectionComplete, lowerComplete, lowerSectionComplete;


    //method to update the upperScore if upper Section is not complete. Sums up all written points
    void updateUpperScore();
    //method that checks if the upperScore is >= 63, if so it writes 35, if not 0
    void updateUpper35();
    //method to update the lowerScore if lower Section is not complete. Sums up all written points
    void updateLowerScore();
    //method to update the lower Score of the upper score, if upper Section is Complete
    void updateLowerUpper();

    //sums all elements of an element up and give the sum back
    int getSumOfArray (const int* array, const int arraySize) const;
    int getSumOfSameValue(const int value, const std::vector<Dice*> *dice) const;
    //sorts an array with insertion sort
    void sortArray(int* array, const int size);
    //tests if an array has a certain amount of the same elements inside by mapping it to a hashmap
    bool validMap(const int NumbersOfAKind, const int* array, const int arraySize);
    bool validMap(const int NumbersOfAKind, const int NumbersOfAKind2, const int* array, const int arraySize);
    //tests if an array has a certain amount of numbers in a row
    bool validStreet(const int NumberOfInRow, int* array, const int arraySize);
    //map that turns an array into a hashmap. The value of elements is the key for the map.
    std::unordered_map<int, std::vector<int>> getMapOfArray(const int* array, const int arraySize);

public:
    //empty default constructor
    Playerscore(){};
    //used c'tor building up the player's score at position, with its name and resource_path
    Playerscore(const sf::Vector2f position, const std::string playername, const std::string texture_path);
    //d'tor deleting dynamically allocated Objects
    ~Playerscore();

    //initializer for the Sections and Scores
    void initUpperSection(const std::string res_path);
    void initLowerSection(const std::string res_path);
    void initScores(const std::string res_path);

    //methods update upper and lower section by writing the finals scores and set the section bools to true
    void updateUpperSection();
    void updateLowerSection();
    //method which calculates the sum of dices for the clicked field
    int calculateUpperField(const int i, const std::vector<Dice*>* dice);
    //method which validates/calculates the dices for the clicked field
    int calculateLowerField(const int i, const std::vector<Dice*>* dice);
    //method to check if the scoreboard is complete
    bool complete();

    //getter
    inline sf::RectangleShape& getShape() { return this->shape; }
    inline Textfield* getTextfield() { return &this->playerNameField; }
    inline std::vector<Button*>* getUpperSection() { return this->upperSection; }
    inline std::vector<Button*>* getLowerSection() { return this->lowerSection; }
    inline bool getUpperSectionComplete() { return this->upperSectionComplete; }
    inline bool getLowerSectionComplete() { return this->lowerSectionComplete; }
    inline Button* getUpperScore() { return this->upperScore; }
    inline Button* getUpper35() { return this->upper35; }
    inline Button* getUpperTotal() { return this->upperTotal; }
    inline Button* getLowerScore() { return this->lowerScore; }
    inline Button* getLowerUpper() { return this->lowerUpper; }
    inline Button* getGrandTotal() { return this->grandTotal; }
};
