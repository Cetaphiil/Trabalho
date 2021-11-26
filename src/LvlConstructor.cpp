#include "LvlConstructor.hpp"
#include "Game.hpp"

LvlConstructor::LvlConstructor(Engine* pG, const Vector2i** map): pGame(pG), map(map){

}

LvlConstructor::~LvlConstructor(){
    
}

void LvlConstructor::setMap(const Vector2i** map){
    map = map;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; i < 10; j++)
        {
           cout << map[i][j].x << map[i][j].y << endl;
        }
    }
}