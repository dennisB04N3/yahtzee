#include "playerscore.h"

Playerscore::Playerscore(const sf::Vector2f position, const std::string name, const std::string res_path)
{
    this->shape.setSize(sf::Vector2f(90.0f, 607.0f));
    this->shape.setPosition(position);
    if(!this->texture.loadFromFile(res_path + "res/player1_field.png"))
    {
        std::cout << "Player's Scorefield texture not found!" << std::endl;
        std::exit(-1);
    }
    this->shape.setTexture(&this->texture);

    this->upperComplete = false;
    this->upperSectionComplete = false;
    this->lowerComplete = false;
    this->lowerSectionComplete = false;

    this->playerNameField = Textfield(sf::Vector2f(position.x + 5, position.y + 4), res_path);
    this->playerNameField.writeText(name);
}

Playerscore::~Playerscore()
{
    for (Button* b : *this->upperSection)
    {
        delete b;
        b = nullptr;
    }
    upperSection = nullptr;
    for (Button* b : *this->lowerSection)
    {
        delete b;
        b = nullptr;
    }
    lowerSection = nullptr;

    delete upperScore;
    delete upper35;
    delete upperTotal;
    delete lowerScore;
    delete lowerUpper;
    delete grandTotal;

    this->upperScore = nullptr;
    this->upper35 = nullptr;
    this->upperTotal = nullptr;
    this->lowerScore = nullptr;
    this->lowerUpper = nullptr;
    this->grandTotal = nullptr;

}

//initialization of Sections and individual Scores
void Playerscore::initUpperSection(const std::string res_path)
{
    this->upperSection = new std::vector<Button*>;
    this->upperSection->push_back(new Button(sf::Vector2f(80,23), sf::Vector2f(this->shape.getPosition().x + 4, 34), res_path));
    this->upperSection->push_back(new Button(sf::Vector2f(80,23), sf::Vector2f(this->shape.getPosition().x + 4, 60), res_path));
    this->upperSection->push_back(new Button(sf::Vector2f(80,23), sf::Vector2f(this->shape.getPosition().x + 4, 87), res_path));
    this->upperSection->push_back(new Button(sf::Vector2f(80,23), sf::Vector2f(this->shape.getPosition().x + 4, 114), res_path));
    this->upperSection->push_back(new Button(sf::Vector2f(80,23), sf::Vector2f(this->shape.getPosition().x + 4, 142), res_path));
    this->upperSection->push_back(new Button(sf::Vector2f(80,23), sf::Vector2f(this->shape.getPosition().x + 4, 169), res_path));
    for (int i = 0; i < 6; i++)
    {
        this->upperSection->at(i)->writeText("");
    }
}

void Playerscore::initLowerSection(const std::string res_path)
{
    this->lowerSection = new std::vector<Button*>;
    this->lowerSection->push_back(new Button(sf::Vector2f(80,23), sf::Vector2f(this->shape.getPosition().x + 4, 309), res_path));
    this->lowerSection->push_back(new Button(sf::Vector2f(80,23), sf::Vector2f(this->shape.getPosition().x + 4, 336), res_path));
    this->lowerSection->push_back(new Button(sf::Vector2f(80,23), sf::Vector2f(this->shape.getPosition().x + 4, 364), res_path));
    this->lowerSection->push_back(new Button(sf::Vector2f(80,23), sf::Vector2f(this->shape.getPosition().x + 4, 391), res_path));
    this->lowerSection->push_back(new Button(sf::Vector2f(80,23), sf::Vector2f(this->shape.getPosition().x + 4, 418), res_path));
    this->lowerSection->push_back(new Button(sf::Vector2f(80,23), sf::Vector2f(this->shape.getPosition().x + 4, 445), res_path));
    this->lowerSection->push_back(new Button(sf::Vector2f(80,23), sf::Vector2f(this->shape.getPosition().x + 4, 481), res_path));
    for (int i = 0; i < 7; i++)
    {
        this->lowerSection->at(i)->writeText("");
    }
}

void Playerscore::initScores(const std::string res_path)
{
    //upper individual scores
    this->upperScore = new Button(sf::Vector2f(80,23), sf::Vector2f(this->shape.getPosition().x + 4, 194), res_path);
    this->upperScore->writeText("");
    this->upper35 = new Button(sf::Vector2f(80,23), sf::Vector2f(this->shape.getPosition().x + 4, 224), res_path);
    this->upper35->writeText("");
    this->upperTotal = new Button(sf::Vector2f(80,23), sf::Vector2f(this->shape.getPosition().x + 4, 253), res_path);
    this->upperTotal->writeText("");
    //lower individual scores
    this->lowerScore = new Button(sf::Vector2f(80, 23), sf::Vector2f(this->shape.getPosition().x + 4, 508), res_path);
    this->lowerScore->writeText("");
    this->lowerUpper = new Button(sf::Vector2f(80, 23), sf::Vector2f(this->shape.getPosition().x + 4, 544), res_path);
    this->lowerUpper->writeText("");
    this->grandTotal = new Button(sf::Vector2f(80, 23), sf::Vector2f(this->shape.getPosition().x + 4, 580), res_path);
    this->grandTotal->writeText("");

}

//Updating upper Section + Scores
void Playerscore::updateUpperScore()
{
    if(this->upperComplete == false)
    {
        int sum = 0;
        bool isCompleted = true;
        for(Button* b : *this->upperSection)
        {
            if(b->isLocked())
            {
                std::string str = b->getText().getString();
                sum += std::stoi(str);
            }
            else
            {
                isCompleted = false;
            }
        }
        this->upperComplete = isCompleted;
        this->upperScore->writeText(std::to_string(sum));
    }
}

void Playerscore::updateUpper35()
{
    std::string str_upperScore = this->upperScore->getText().getString();
    int i_upperScore = std::stoi(str_upperScore);

    if(i_upperScore >= 63)
    {
        this->upper35->writeText("35");
    }
    else
    {
        this->upper35->writeText("0");
    }
}

void Playerscore::updateUpperSection()
{
    if(this->upperSectionComplete == false)
    {
        this->updateUpperScore();
        this->updateUpper35();
        if(this->upperComplete)
        {
            std::string str_upperScore = this->upperScore->getText().getString();
            std::string str_upper35 = this->upper35->getText().getString();
            int totalScore = std::stoi(str_upperScore) + std::stoi(str_upper35);
            this->upperTotal->writeText(std::to_string(totalScore));
            this->upperSectionComplete = true;
        }
    }
}

//Updating lower Section + Scores
void Playerscore::updateLowerScore()
{
    if(this->lowerComplete == false)
    {
        int sum = 0;
        bool isCompleted = true;
        for(Button* b : *this->lowerSection)
        {
            if(b->isLocked())
            {
                std::string str = b->getText().getString();
                sum += std::stoi(str);
            }
            else
            {
                isCompleted = false;
            }
        }
        this->lowerComplete = isCompleted;
        this->lowerScore->writeText(std::to_string(sum));
    }
}

void Playerscore::updateLowerUpper()
{
    if(this->upperComplete == true)
    {
        this->lowerUpper->writeText(this->upperTotal->getText().getString());
    }
}

void Playerscore::updateLowerSection()
{
    if(this->lowerSectionComplete == false)
    {
        this->updateLowerScore();
        this->updateLowerUpper();
        if(this->lowerComplete)
        {
            std::string str_upperTotal = this->upperTotal->getText().getString();
            std::string str_lowerScore = this->lowerScore->getText().getString();
            int totalScore = std::stoi(str_upperTotal) + std::stoi(str_lowerScore);
            this->grandTotal->writeText(std::to_string(totalScore));
            this->lowerSectionComplete = true;
        }
    }
}


int Playerscore::getSumOfSameValue(int value, const std::vector<Dice*> *dices) const
{
    int sum = 0;
    for (Dice* d : *dices)
    {
        if (d->getValue() == value)
        {
            sum += d->getValue();
        }
    }
    return sum;
}

int Playerscore::calculateUpperField(const int i, const std::vector<Dice*> *dice)
{
    int sum = 0;
    switch(i)
    {
    case 0:
        sum = getSumOfSameValue(1, dice);
        break;

    case 1:
        sum = getSumOfSameValue(2, dice);
        break;

    case 2:
        sum = getSumOfSameValue(3, dice);
        break;

    case 3:
        sum = getSumOfSameValue(4, dice);
        break;

    case 4:
        sum = getSumOfSameValue(5, dice);
        break;

    case 5:
        sum = getSumOfSameValue(6, dice);
        break;

    default:
        break;
    }
    return sum;
}

int Playerscore::calculateLowerField(const int i, const std::vector<Dice*> *dice)
{
    int index = 0;
    int array[5] = { 0 };
    int* p_array = &array[0];
    int arraySize = (sizeof(array))/ (sizeof(array[0]));
    int sum = 0;

    for (Dice* d : *dice)
    {
        p_array[index] = d->getValue();
        index++;
    }

    switch(i)
    {
    case 0://3 of a kind, count all
        if(validMap(3, p_array, arraySize))
        {
            sum = this->getSumOfArray(p_array, arraySize);
        }
        break;

    case 1://4 of a kind, count all
        if(validMap(4, p_array, arraySize))
        {
            sum = this->getSumOfArray(p_array, arraySize);
        }
        break;

    case 2://full house
        if(validMap(3, 2, p_array, arraySize))
        {
            sum = 25;
        }
        break;

    case 3://small street
        if(validStreet(4, p_array, arraySize))
        {
            sum = 30;
        }
        break;

    case 4://big street
        if(validStreet(5, p_array, arraySize))
        {
            sum = 40;
        }
        break;

    case 5://yahtzee
        if(validMap(5, p_array, arraySize))
        {
            sum = 50;
        }
        break;

    case 6://chance
        sum = this->getSumOfArray(p_array, arraySize);
        break;

    default:
        break;
    }

    return sum;
}

int Playerscore::getSumOfArray(const int* array, const int arraySize) const
{
    int sum = 0;
    for (int i = 0; i < arraySize; i++)
    {
        sum += array[i];
    }

    return sum;
}

bool Playerscore::validMap(const int NumbersOfAKind, const int* array, const int arraySize)
{
    bool test = false;
    std::unordered_map<int, std::vector<int>> um = getMapOfArray(array, arraySize);

    for (auto& k : um)
    {
        if((signed int)k.second.size() >= NumbersOfAKind)
        {
            test = true;
            break;
        }
    }

    return test;
}

bool Playerscore::validMap(const int NumbersOfAKind1, const int NumbersOfAKind2, const int* array, const int arraySize)
{
    bool test1 = false, test2 = false;
    std::unordered_map<int, std::vector<int>> um = getMapOfArray(array, arraySize);
    int size = 0;
    for (auto& k : um)
    {
        size = k.second.size();

        if(size >= NumbersOfAKind1)
        {
            test1 = true;
        }
        if(size >= NumbersOfAKind2)
        {
            test2 = true;
        }
    }

    return (test1 && test2);
}

bool Playerscore::validStreet(const int NumberOfInRow, int *array, const int arraySize)
{
    bool test = false;
    sortArray(array, arraySize);

    std::vector<int> testVec;

    for (int i = 1; i <= arraySize; i++)
    {
        if (array[i] > array[i - 1])
        {
            testVec.push_back(0);
        }
    }

    if((signed int)testVec.size() >= NumberOfInRow - 1)
    {
        test = true;
    }

    return test;
}

//sorting the values by insertion sort
void Playerscore::sortArray(int* array, const int size)
{
    int i, num, j;
    for (i = 1; i < size; i++)
    {
        num = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > num)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = num;
    }
}

std::unordered_map<int, std::vector<int>> Playerscore::getMapOfArray(const int *array, const int arraySize)
{
    std::unordered_map<int, std::vector<int>> um;
    for(int i = 0; i < arraySize; i++)
    {
        um[array[i]].push_back(0);
    }

    return um;
}

bool Playerscore::complete()
{
    return (this->lowerSectionComplete && this->upperSectionComplete);
}
