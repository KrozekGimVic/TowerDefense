#ifndef GAMEMAP_HPP
#define GAMEMAP_HPP

#include "globals.hpp"
#include "Enums.hpp"
#include "Field.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Game;

class GameMap{
    int size, windowSize, fieldWidth;
    std::vector<std::vector<Field>> Map;
public:
    GameMap(){}
    GameMap(int windowHeight);

    Field* get(int i, int j){ return &Map[i][j]; }
    int getSize() const{ return size; }
    int getFieldWidth() const{ return fieldWidth; }

    bool inMap(const sf::Vector2i& pos) const;
    int* getField(const sf::Vector2i& pos) const;
};

#endif
