#include "Wall.hpp"

Wall::Wall(Vector2f posit, int kind): Obstacle(){
    setKind(kind);
    setPosition(posit);
    setShowing();
    damage = 0;
    loader();
}

Wall::~Wall(){

}

void Wall::loader() {
    texture.loadFromFile(WALL);
    sprite.setTexture(texture);
} 

void Wall::collide(Entity* other){
    
}