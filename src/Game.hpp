#ifndef GAME_HPP
#define GAME_HPP

#include "Enums.hpp"
#include "globals.hpp"
#include "Button.hpp"
#include "GameMap.hpp"
#include "Enemy.hpp"
#include "EnemySpawner.hpp"
#include "Tower.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

class Game {
    sf::RenderWindow window;
    bool fastForward =  false;
    std::vector<sf::Sprite*> drawable;

    int lastClickedID;
    std::vector<Button> towerButtons;
    Button startButton, pauseButton;
    sf::Text statusText, towerDesc;

    bool running, waveRunning;
    int Lives, Money;

    GameMap Map;
    std::vector<Enemy> enemies;
    EnemySpawner Spawner;
    std::vector<Tower> Towers;
    std::vector<Particle> particles;

    void update();
    void handleMouseClick();
    void addDrawable(sf::Sprite* sprite);
    sf::Text createTextField(int posx, int posy, std::string strText, int textSize);
public:
    Game();
    void run();
    std::vector<int> getSize(){ return std::vector<int>(sizeX, sizeY); }
};

#endif
