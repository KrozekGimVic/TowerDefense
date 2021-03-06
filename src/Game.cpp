#include "Game.hpp"

Game::Game(){
    loader.loadTextures();
    loader.loadMaps();
    loader.loadFont();
    loader.loadWaves();
    loader.calculatePath();
    std::string towerDescString = loader.loadTowerDesc();

    window.create(sf::VideoMode(sizeX, sizeY), "Tower Defense");
    window.setFramerateLimit(30);
    window.setMouseCursorVisible(false);
    lastClickedTower.setPosition(605, sizeY);   // out of screen
    lastClickedTower.setTexture(*loader.getMouseTextures(2));

    running = false, waveRunning = false;
    Money = 200, Lives = 20;
    lastClickedID = 0;
    towerButtons = createTowerButtons();
    startButton = Button(705, 540, 0);
    pauseButton = Button(605, 540, 1);
    statusText = createTextField(605, 0, "", 22);
    towerDesc = createTextField(645, 100, towerDescString, 15);

    for(Button& button : towerButtons){
        addDrawable(&button);
    }
    addDrawable(&startButton);
    addDrawable(&pauseButton);

    Map = GameMap(sizeY);
    for(int i=0; i<loader.getMapSize(); ++i){
        for(int j=0; j<loader.getMapSize(); ++j){
            addDrawable(Map.get(i, j));
        }
    }
    Spawner.setup();
}

void Game::run(){
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            switch(event.type){
                case sf::Event::KeyPressed:
                    if(event.key.code == sf::Keyboard::F){
                        if(fastForward) window.setFramerateLimit(30);
                        else window.setFramerateLimit(60);
                        std::cout << "Fast Forward: " << std::boolalpha << !fastForward << std::endl;
                        fastForward = !fastForward;
                    }
                    if(!(event.key.code == sf::Keyboard::Escape)) break;
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left) handleMouseClick();
                default: break;
            }
        }
        if(running){
            Spawner.spawn(enemies);
            Spawner.move(enemies, Money, Lives);

            for(Tower& tower : Towers){
                tower.shoot(enemies, particles);
            }
            updateParticles(particles);

            if(Spawner.movingFinished()){
                running = false;
                particles = {};
            }
            if(Lives <= 0) window.close();      // could be better
        }

        statusText.setString("Lives: "+std::to_string(Lives) +
                            "\nMoney: "+std::to_string(Money) +
                            "$\nWave: "+std::to_string(Spawner.getWave()+1)+"/"+std::to_string(Spawner.getMaxWaves())
                        );

        handleMouseCursor();
        update();
    }
}

void Game::update(){
    window.clear(sf::Color(90, 106, 41));

    for(sf::Sprite* sprite : drawable){
        window.draw(*sprite);
    }
    for(Enemy& enemy : enemies){
        window.draw(enemy);
    }
    for(Particle& particle : particles){
        window.draw(particle);
    }
    window.draw(statusText);
    window.draw(towerDesc);
    window.draw(lastClickedTower);
    window.draw(mouseCursor);
    window.display();
}
void Game::handleMouseCursor(){
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    if(Map.inMap(mousePos)){
        int *pos = Map.getField(mousePos);
        float fieldWidth = static_cast<float>(sizeY) / loader.getMapSize();
        mouseCursor.setPosition(fieldWidth*pos[0], fieldWidth*pos[1]);
        mouseCursor.setTexture(*loader.getMouseTextures(1));
    }else{
        mouseCursor.setPosition(static_cast<sf::Vector2f>(mousePos));
        mouseCursor.setTexture(*loader.getMouseTextures(0));
    }
}
void Game::handleMouseClick(){
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    if(Map.inMap(mousePos)){
        if(lastClickedID > 1){
            int *pos = Map.getField(mousePos);
            Field *field = Map.get(pos[0], pos[1]);
            placeTower(Money, field, Towers, static_cast<fieldClass>(lastClickedID));
            lastClickedID = 0;
            lastClickedTower.setPosition(lastClickedTower.getPosition().x, sizeY);
        }
    }else if(startButton.isClicked(mousePos)){
        if(!Spawner.isRunning()){       // && enemies.size() == 0){
            if(!Spawner.endOfWaves()) Spawner.start();
        }
        running = true;
    }else if(pauseButton.isClicked(mousePos)){
        running = false;
    }for(Button& button : towerButtons){
        if(button.isClicked(mousePos)){
            lastClickedID = button.getID();
            lastClickedTower.setPosition(lastClickedTower.getPosition().x, 100*(button.getID()-1));
        }
    }
}

void Game::addDrawable(sf::Sprite* sprite){
    drawable.push_back(sprite);
}

sf::Text Game::createTextField(int posx, int posy, std::string strText, int textSize){
    sf::Text textField(strText, *(loader.getFont()));
    textField.setPosition(posx, posy);
    textField.setColor(sf::Color(188, 175, 105));
    textField.setCharacterSize(textSize);
    return textField;
}
