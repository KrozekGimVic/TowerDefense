#ifndef Tower_hpp
#define Tower_hpp

#include "globals.hpp"
#include "Field.hpp"
#include "Particle.hpp"
#include "Enemy.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Tower{
    Field* field;
    fieldClass id;
    int step, shootdelay, strength;
    float range;
public:
    Tower(){}
    Tower(Field* field, fieldClass classID);
    void shoot(std::vector<Enemy>& enemies, std::vector<Particle>& particles);
};

#endif
