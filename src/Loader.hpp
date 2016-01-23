#ifndef Loader_hpp
#define Loader_hpp

#include "Enums.hpp"
#include <SFML/Graphics.hpp>
#include <cassert>
#include <fstream>
#include <iostream>

class Loader{
    sf::Texture fieldTextures[5], enemyTextures[9], buttonTextures[2], particleTexture;
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
    }sf::Texture* getParticleTexture(){
        return &particleTexture;
    }
};

#endif
