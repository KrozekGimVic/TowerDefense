#include "EnemySpawner.hpp"

EnemySpawner::EnemySpawner(): wave(0), step(0), spawnTimer(0){}

void EnemySpawner::setup(){
    int startx = loader.getStart();
    startx *= sizeY;
    startx /= loader.getMapSize();
    startVect = sf::Vector2f(startx, 0);
}

void EnemySpawner::start(){
    waveRunning = true;
    endOfMoving = false;
}
void EnemySpawner::stop(){
    waveRunning = false;
}

void EnemySpawner::spawn(std::vector<Enemy>& enemies){
    if(!waveRunning) return;
    if(spawnTimer%15 == 0){
        spawnTimer = 0;
        if(int((*loader.getWaves())[wave].length()) <= step){
            waveRunning = false;
            step = 0;
            spawnTimer = 0;
            wave++;
        }else{
            int enemyClass = static_cast<int>((*loader.getWaves())[wave][step])-static_cast<int>('a');
            enemies.push_back(Enemy(startVect, enemyClass, sizeY/loader.getMapSize()));
            step++;
        }
    }
    spawnTimer++;
}

void EnemySpawner::move(std::vector<Enemy>& enemies, int& Money, int& Lives){
    auto i=enemies.begin();
    while(i!=enemies.end()){
        if(!i->go(*loader.getPath())){       // if enemy cannot move
            if(i->isDead()){
                Money += i->getValue();
                i = enemies.erase(i);
            }else{
                Lives -= i->getLives();
                i = enemies.erase(i);
                if(enemies.size() == 0){
                    endOfMoving = true;
                }
            }
        }else{ ++i; }
    }
}
int EnemySpawner::getMaxWaves(){
    return (*loader.getWaves()).size();
}
bool EnemySpawner::endOfWaves(){
    return wave == (int) getMaxWaves()-1;
}
