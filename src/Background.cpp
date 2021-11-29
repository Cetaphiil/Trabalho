#include <Background.hpp>

Background::Background(): Entity(){
}

Background::~Background(){

}

void Background::loader(int whatlvl) {
    if(whatlvl == 1){
        if(!texture.loadFromFile(BACKLVL1)){
            exit (1);
        }
        texture.loadFromFile(BACKLVL1);
        sprite.setTexture(texture);
    }else if(whatlvl == 2){
        if(!texture.loadFromFile(BACKLVL2)){
            exit (1);
        }
        texture.loadFromFile(BACKLVL2);
        sprite.setTexture(texture);
    }
}

void Background::update(sf::Vector2f pos){
    sprite.setPosition(pos);
}


void Background::show(sf::RenderWindow *window){
    window->draw(sprite);
}