#include "Button.hpp"

Button::Button(int posx, int posy, int textureID){
    id = textureID;
    setPosition(posx, posy);
    setTexture(*loader.getButtonTexture(textureID));
    sf::FloatRect rect = getLocalBounds();
    width = rect.width;
    height = rect.height;
}
Button::Button(int posx, int posy, fieldClass textureID){
    id = textureID;
    setPosition(posx, posy);
    setTexture(*loader.getFieldTexture(textureID));
    sf::FloatRect rect = getLocalBounds();
    width = rect.width;
    height = rect.height;
}
bool Button::isClicked(const sf::Vector2i& click){
    sf::Vector2f pos = getPosition();
    int x = click.x - pos.x, y = click.y - pos.y;
    return 0 < x && x < width && 0 < y && y < height;
}

std::vector<Button> createTowerButtons(){
    std::vector<Button> towerButtons;
    towerButtons.push_back( Button(605, 100, BASIC_TOWER) );
    towerButtons.push_back( Button(605, 200, CIRCLE_TOWER));
    towerButtons.push_back( Button(605, 300, POWER_TOWER));
    return towerButtons;
}
