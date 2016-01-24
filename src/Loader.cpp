#include "Loader.hpp"

void Loader::loadTextures(){
    fieldTextures[0].loadFromFile("data/images/grass.jpg");
    fieldTextures[1].loadFromFile("data/images/path.jpg");
    fieldTextures[2].loadFromFile("data/images/tower0.gif");
    fieldTextures[3].loadFromFile("data/images/tower1.gif");
    fieldTextures[4].loadFromFile("data/images/tower2.gif");

    for(int i = 0; i<int(sizeof(enemyTextures)/sizeof(sf::Texture)); ++i){
        enemyTextures[i].loadFromFile("data/images/enemy"+std::to_string(i)+".gif");
    }

    buttonTextures[0].loadFromFile("data/images/buttonstart.gif");
    buttonTextures[1].loadFromFile("data/images/buttonpause.gif");
    particleTexture.loadFromFile("data/images/particle.gif");
}
void Loader::loadMaps(){
    std::ifstream mapFile;
    mapFile.open("data/map.1");
    assert(mapFile.is_open());
    while(!mapFile.eof()){
        std::string line;
        mapFile >> line;
        if(line != "") MAPOFTHEGAME.push_back(line);
    }
    mapFile.close();
    mapSize = MAPOFTHEGAME.size();
}
void Loader::loadWaves(){
    std::ifstream waveFile;
    Waves = {};
    waveFile.open("data/waves.1");
    assert(waveFile.is_open());
    while(!waveFile.eof()){
        std::string line;
        waveFile >> line;
        Waves.push_back(line);
    }
    waveFile.close();
}
void Loader::loadFont(){
    Font.loadFromFile("data/Roboto-Regular.ttf");
}
int Loader::findStart(){
    for(int i=0; i<mapSize; ++i){
        if(MAPOFTHEGAME[i][0] == '#'){
            return i;
        }
    }
    return -1;
}
void Loader::calculatePath(){
    // gre po potki, start more bit na levi strani
    Path = {};
    std::vector<int> last = {-1, -1};
    start = findStart();
    int i = start,  j = 0;

    assert(i >= 0 && "Start of the map must be on the left side!");
    Path.push_back(RIGHT);
    while(i>=0 && j>=0 && i<mapSize && j<mapSize){
        if(last[0]!=i+1 && i<mapSize-1 && MAPOFTHEGAME[i+1][j] == '#'){
            Path.push_back(DOWN);
            last = {i, j};
            i++;
        }else if(last[0]!=i-1 && i>0 && MAPOFTHEGAME[i-1][j] == '#'){
            Path.push_back(UP);
            last = {i, j};
            i--;
        }else if(last[1]!=j+1 && j<mapSize-1 && MAPOFTHEGAME[i][j+1] == '#'){
            Path.push_back(RIGHT);
            last = {i, j};
            j++;
        }else if(last[1]!=j-1 && j>0 && MAPOFTHEGAME[i][j-1] == '#'){
            Path.push_back(LEFT);
            last = {i, j};
            j--;
        }else{ break; }
    }
}

std::string Loader::loadTowerDesc(){
    std::ifstream data;
    std::string out = "";
    data.open("data/towers");
    assert(data.is_open());
    while(!data.eof()){
        std::string line;
        std::getline(data, line);
        out.append(line + "\n");
    }
    data.close();
    return out;
}
