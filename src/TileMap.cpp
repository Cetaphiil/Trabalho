#include "TileMap.hpp"

#include <fstream>


Map::Map(const char* tileDir): Entity(){
    initMap(tileDir);
}

void Map::initMap(const char* lvlDir) {
    std::ifstream openfile(lvlDir);
    loadCounter = sf::Vector2i(0, 0);
    if(openfile.is_open()){
        while(!openfile.eof()){
            std::string str;
            openfile >> str;
            char x = str[0], y = str[2];
            map[loadCounter.x][loadCounter.y] = sf::Vector2i(x - '0' ,y - '0');
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

Vector2i Map::getMap(int i, int j) {
    return map[i][j];
}