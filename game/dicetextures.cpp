#include "dicetextures.h"

DiceTextures::DiceTextures(const std::string res_path)
{
    for (int i = 0; i < 6; i++)
    {
        this->dice_textures.push_back(new sf::Texture());
        if(!this->dice_textures.at(i)->loadFromFile(res_path + "res/" + std::to_string(i + 1) + "eye.png"))
        {
            std::cout << "dice textures not found!" << std::endl;
            std::exit(-1);
        }
    }

    for (int i = 0; i < 6; i++)
    {
        this->dice_selected_textures.push_back(new sf::Texture());
        if(!this->dice_selected_textures.at(i)->loadFromFile(res_path +"res/" + std::to_string(i + 1) + "eyeS.png"))
        {
            std::cout << "dice textures not found!" << std::endl;
            std::exit(-1);
        }

    }
}

DiceTextures::~DiceTextures()
{
    /*Bug we couldnt solve. When code is active textures of dices are not reliable although d'tor
     * is not called before game's end
     */
//    for (sf::Texture* t : dice_textures)
//    {
//        delete t;
//        t = nullptr;
//    }
//    for (sf::Texture* t : dice_selected_textures)
//    {
//        delete t;
//        t = nullptr;
//    }
}
