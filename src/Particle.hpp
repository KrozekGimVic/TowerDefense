#ifndef Particle_hpp
#define Particle_hpp

#include "globals.hpp"
#include "Enemy.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

class Particle: public sf::Sprite{
    Enemy* target;
    int lasts, speed, strength, fieldSize;
    bool hitTarget;
public:
    Particle(int posx, int posy, Enemy* target_, int strength_, int fieldSize_);
    bool alive();
};

#endif
