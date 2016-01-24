#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "globals.hpp"
#include "Enums.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class Button: public sf::Sprite{
    int width, height, id;
public:
    Button(){}
    Button(int posx, int posy, int textureID);
    Button(int posx, int posy, fieldClass textureID);     // dvakrat ker ni posebej slikic za gumbe in uporabljam tiste k na polju.
    int getID(){ return id; }
    bool isClicked(const sf::Vector2i& click);
};

std::vector<Button> createTowerButtons();

#endif
