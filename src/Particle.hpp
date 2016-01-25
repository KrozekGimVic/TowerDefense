#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "globals.hpp"
#include "Enemy.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>

class Particle: public sf::Sprite{
    Enemy* target;
    int lasts, speed, strength, fieldSize;
    bool hitTarget, ice;
public:
    Particle(int posx, int posy, Enemy* target_, int strength_, int fieldSize_, int id, bool ice_);
    bool alive();
};

void updateParticles(std::vector<Particle>& particles);

#endif
