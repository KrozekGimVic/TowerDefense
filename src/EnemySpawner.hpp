#ifndef ENEMYSPAWNER_HPP
#define ENEMYSPAWNER_HPP

#include "globals.hpp"
#include "Enemy.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class EnemySpawner{
    int wave, step, spawnTimer;
    sf::Vector2f startVect;
    bool waveRunning, endOfMoving;
public:
    EnemySpawner();
    void setup();
    void start();
    void stop();
    void spawn(std::vector<Enemy>& enemies);
    void move(std::vector<Enemy>& enemies, int& Money, int& Lives);
    int getMaxWaves();
    bool endOfWaves();
    bool isRunning(){ return waveRunning; }
    bool movingFinished(){ return endOfMoving; }
    int getWave(){ return wave; }
};

#endif
