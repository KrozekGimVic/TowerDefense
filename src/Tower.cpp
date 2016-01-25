#include "Tower.hpp"

Tower::Tower(Field* field_, fieldClass classID):field(field_), id(classID), step(0){
    field->setClass(classID);
    switch(classID){
        case BASIC_TOWER:
            strength = 1; range = 65*65; shootdelay = 45;
            break;
        case CIRCLE_TOWER:
            strength = 1; range = 55*55; shootdelay = 85;
            break;
        case POWER_TOWER:
            strength = 2; range = 65*65; shootdelay = 45;
            break;
        case ICE_TOWER:
            strength = 0; range = 55*55; shootdelay = 85;
            break;
        default:
            assert(!"This field id is not defined as tower!");
    }
}
void Tower::shoot(std::vector<Enemy>& enemies, std::vector<Particle>& particles){
    if(step % shootdelay == 0){
        sf::Vector2f pos = field->getPosition();
        for(Enemy& enemy : enemies){
            sf::Vector2f enemyPos = enemy.getPosition();
            float dis = std::pow(pos.x-enemyPos.x + field->getSize()/2, 2) +
                        std::pow(pos.y-enemyPos.y + field->getSize()/2, 2);
            if(dis < range){
                step = 1;
                particles.push_back(Particle(pos.x+field->getSize()/2, pos.y+field->getSize()/2,
                                &enemy, strength, field->getSize(), id-2, id==ICE_TOWER));
                if(id != CIRCLE_TOWER && id != ICE_TOWER){ break; }
            }
        }
    }else{
        step++;
    }
}

bool placeTower(int& Money, Field *field, std::vector<Tower>& Towers, const fieldClass towerID){
    int price = towerPrices[static_cast<int>(towerID)];
    if(Money >= price && field->getClass() == GRASS){
        Money -= price;
        Tower tower(field, towerID);
        Towers.push_back(tower);
        return true;
    }
    return false;
}
