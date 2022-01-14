/****************************************************************************
C++ SoSe 2021
Projekt C++
kniffel2P
Dennis Bohnenschäfer 364772, Parisa Shasti 311771, Maarten van den Boom 311934
*****************************************************************************/
#include<QDir>
#include<QString>
#include"game.h"
#include<iostream>

// function to get the names of the players
void getNames(char*, char*);
// function to get a dynamic path to current location
std::string getProjectPath();

/* Function builds the path to current dir, gets the name of the players via console,
 * builds the game and than starts the game loop of the game (start()).
 */
int main()
{
    //building path
    const std::string res_path = getProjectPath();
    //building names
    char* name1 = new char[100];
    char* name2 = new char[100];
    getNames(name1, name2);
    std::string player1(name1), player2(name2);
    //game build and start
    Game game(player1, player2, res_path);
    game.start();

    delete[] name1;
    delete[] name2;
    name1 = name2 = nullptr;

    return 0;
}

std::string getProjectPath()
{
    QString str = QDir().currentPath();
    std::string res_path = str.toStdString();
    std::string clean_path = "";
    for(int i = res_path.size() - 1; i >= 0; i--)
    {
        if(res_path.at(i) == '/')
        {
            clean_path = res_path.substr(0, i + 1);
            break;
        }
    }
    res_path = clean_path + "kniffel2P/";
    return res_path;
}

void getNames(char* name1, char* name2)
{
    std::cout << "Player 1 please enter your name: " << std::endl;
//    std::cin >> name1;
    std::cin.getline(name1, 100);
    std::cout << "Player 2 please enter your name: " << std::endl;
//    std::cin >> name2;
    std::cin.getline(name2, 100);
}
