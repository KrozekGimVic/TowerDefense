#include "Enemy.hpp"

Enemy::Enemy(sf::Vector2f pos, int id, float fieldWidth):sf::Sprite(){
    pos.x += fieldWidth/2;
    pos.y -= fieldWidth/2;
    setPosition(pos);
    setOrigin(10, 10);      // sirina enemy-a 20px
    setTexture(*loader.getEnemyTexture(id));
    dead = false;
    value = lives = id+1;     // zaenkrat tolk kot ma id tolk ma zivljenja
    location = counter = 0;
    speed = 2;
    steps = fieldWidth/speed;
}
void Enemy::hurt(int amount){
    lives -= amount;
    if(lives <= 0){
        dead = true;
    }else{
        setTexture(*loader.getEnemyTexture(lives-1));
    }
}
bool Enemy::go(std::vector<directions>& path){
    if(dead || location >= path.size()){
        return false;
    }
    switch(path[location]){
        case RIGHT:
            move(0, speed);
            break;
        case LEFT:
            move(0, -speed);
            break;
        case UP:
            move(-speed, 0);
            break;
        case DOWN:
            move(speed, 0);
            break;
    }
    counter++;
    if(counter >= steps){
        counter = counter%steps;
        location++;
    }
    return true;
}
