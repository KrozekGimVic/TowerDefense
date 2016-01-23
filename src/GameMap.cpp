#include "GameMap.hpp"

GameMap::GameMap(int windowHeight):size(loader.getMapSize()), windowSize(windowHeight){
    fieldWidth = windowSize/size;
    for(int i=0; i<size; ++i){
        Map.push_back({});
        for(int j=0; j<size; ++j){
            Map[i].push_back(Field(fieldWidth, i*fieldWidth, j*fieldWidth));
            if((*loader.getMapOfTheGame())[i][j] == '#'){
                get(i, j)->setClass(PATH);
            }
        }
    }
}
bool GameMap::inMap(const sf::Vector2i& pos) const{
    bool x = 0 < pos.x && pos.x < windowSize;
    bool y = 0 < pos.y && pos.y < windowSize;
    return x && y;
}
int* GameMap::getField(const sf::Vector2i& pos) const{
    assert(inMap(pos) && "Vector pos is not in map!");
    static int field[2];
    field[0] = pos.x / fieldWidth;
    field[1] = pos.y / fieldWidth;
    return field;
}
