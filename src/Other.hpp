#ifndef Other_hpp
#define Other_hpp

#include "globals.hpp"
#include "Enums.hpp"
#include "Tower.hpp"
#include "Particle.hpp"
#include "Button.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

bool placeTower(int& Money, Field* field, std::vector<Tower>& Towers, const fieldClass towerID);
void updateParticles(std::vector<Particle>& particles);

std::vector<Button> createTowerButtons();
sf::Text createTextField(int posx, int posy, std::string strText, int textSize);

#endif
