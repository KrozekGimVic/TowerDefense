#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Enums.hpp"
#include "globals.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class Enemy: public sf::Sprite{
    int lives, counter, steps, value, freezeCounter;
    unsigned int location;
    float speed;
    bool dead, freezed;
public:
    Enemy(sf::Vector2f pos, int id, float fieldWidth);

    int getValue(){ return std::max(value/2+1, 2); }
    int getLives(){ return lives; }
    bool isDead(){ return dead; }
    bool isFreezed(){ return freezed; }
    void freeze();
    void hurt(int amount);
    bool go(std::vector<directions>& path);
};

#endif
