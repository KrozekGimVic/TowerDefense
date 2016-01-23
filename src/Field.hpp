#ifndef Field_hpp
#define Field_hpp

#include "Enums.hpp"
#include "globals.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class Field: public sf::Sprite{
    int size;
    fieldClass classID;
public:
    Field(){}
    Field(int size_, float posx, float posy);
    int getClass() const{ return classID; };
    void setClass(fieldClass classID_);
    int getSize() const{ return size; }
};

#endif
