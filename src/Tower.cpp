#include "Tower.hpp"

Tower::Tower(Field* field_, fieldClass classID):field(field_), id(classID), step(0){
    field->setClass(classID);
    switch(classID){
        case BASIC_TOWER:
            strength = 1; range = 65*65; shootdelay = 40;
            break;
        case CIRCLE_TOWER:
            strength = 1; range = 45*45; shootdelay = 75;
            break;
        case POWER_TOWER:
            strength = 2; range = 65*65; shootdelay = 45;
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
                                    &enemy, strength, field->getSize()));
                if(id != CIRCLE_TOWER){ break; }
            }
        }
    }else{
        step++;
    }
}
