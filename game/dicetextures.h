#pragma once
#include"SFML/Graphics.hpp"
#include<vector>
#include<iostream>
/* Simple Resource holder Class.
 * All textures are in two vectors, which is 6 long (6 sides)
 * and holds the selected and not selected textures for the Dice Class.
 */
class DiceTextures
{
private:
    //attributes - textures
    std::vector<sf::Texture*> dice_textures;
    std::vector<sf::Texture*> dice_selected_textures;
public:
    //empty default c'tor
    DiceTextures(){};
    //used c'tor loading the textures
    DiceTextures(const std::string res_path);
    //Work to be Done
    ~DiceTextures();

    //getter - Texture at index
    inline sf::Texture* getTextureAt(const int index) { return this->dice_textures.at(index); }
    inline sf::Texture* getSelectedTextureAt(const int index) { return this->dice_selected_textures.at(index); }
};
