#ifndef LOADER_HPP
#define LOADER_HPP

#include "Enums.hpp"
#include <SFML/Graphics.hpp>
#include <cassert>
#include <fstream>
#include <iostream>

class Loader{
    sf::Texture fieldTextures[6], enemyTextures[8], buttonTextures[2], particleTextures[4], mouseTextures[3];
    std::vector<std::string> MAPOFTHEGAME;
    std::vector<std::string> Waves;
    std::vector<directions> Path;
    sf::Font Font;
    int mapSize, start;

    int findStart();
public:
    Loader(){}
    void loadTextures();
    void loadMaps();
    void loadFont();
    void loadWaves();
    void calculatePath();
    std::string loadTowerDesc();

    std::vector<std::string>* getMapOfTheGame(){
        return &MAPOFTHEGAME;
    }
    std::vector<std::string>* getWaves(){
        return &Waves;
    }
    std::vector<directions>* getPath(){
        return &Path;
    }
    sf::Font* getFont(){
        return &Font;
    }
    int getMapSize(){
        return mapSize;
    }
    int getStart(){
        return start;
    }
    sf::Texture* getFieldTexture(fieldClass field){
        return &(fieldTextures[static_cast<int>(field)]);
    }sf::Texture* getEnemyTexture(int enemyID){
        return &(enemyTextures[enemyID]);
    }sf::Texture* getButtonTexture(int buttonID){
        return &(buttonTextures[buttonID]);
    }sf::Texture* getParticleTextures(int particleID){
        return &(particleTextures[particleID]);
    }sf::Texture* getMouseTextures(int id){
        return &(mouseTextures[id]);
    }
};

#endif
