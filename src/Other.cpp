#include "Other.hpp"

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

void updateParticles(std::vector<Particle>& particles){
    auto i=particles.begin();
    while(i!=particles.end()){
        if(!i->alive()){
            i = particles.erase(i);
        }else{ ++i; }
    }
}

std::vector<Button> createTowerButtons(){
    std::vector<Button> towerButtons;
    towerButtons.push_back( Button(605, 100, BASIC_TOWER) );
    towerButtons.push_back( Button(605, 200, CIRCLE_TOWER));
    towerButtons.push_back( Button(605, 300, POWER_TOWER));
    return towerButtons;
}

sf::Text createTextField(int posx, int posy, std::string strText, int textSize){
    sf::Text textField(strText, *(loader.getFont()));
    textField.setPosition(posx, posy);
    textField.setColor(sf::Color(188, 175, 105));
    textField.setCharacterSize(textSize);
    return textField;
}
