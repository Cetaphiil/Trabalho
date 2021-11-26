#include "TileMap.hpp"

Map::Map(string tileDir): Entity(){
    fstream openfile(tileDir);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            string str;
            openfile >> str;
            textureList[i][j].loadFromFile(str);
            }
    }
}

void Map::initMap(string lvlDir) {
    fstream openfile(lvlDir);
    loadCounter = sf::Vector2i(0, 0);
    if(openfile.is_open()){
        while(!openfile.eof()){
            std::string str;
            openfile >> str;
            char x = str[0], y = str[2];
            if(!isdigit(x) || !isdigit(y)){
                map[loadCounter.x][loadCounter.y] = sf::Vector2i(-1 ,-1);
            }
            else{
                map[loadCounter.x][loadCounter.y] = sf::Vector2i(x - '0' ,y - '0');
            }
            if(openfile.peek() == '\n'){
                loadCounter.x = 0;
                loadCounter.y++;
            }
            else{
                loadCounter.x++;
            }
        }
        loadCounter.y++;
    }
}

void Map::loadTileMap(RenderWindow *window) {
    for (int i = 0; i < loadCounter.x; ++i) {
        for (int j = 0; j < loadCounter.y; ++j) {
            if(map[i][j].x != -1 && map[i][j].y != -1){
                sprite.setPosition(i*128, j*128);
                sprite.setTexture(textureList[map[i][j].x][map[i][j].y]);
                window->draw(sprite);
            }
        }
    }
}