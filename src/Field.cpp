#include "Field.hpp"

Field::Field(int size_, float posx, float posy):sf::Sprite(), size(size_){
    setPosition(posx, posy);
    setClass(GRASS);
}
void Field::setClass(fieldClass classID_){
    classID = classID_;
    setTexture(*loader.getFieldTexture(classID));
}
