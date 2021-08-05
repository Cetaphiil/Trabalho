#include "Game.hpp"
int main() {
    Engine game;
    while(game.windowOpen()){
        
        game.render();
        
        game.update();
        
        game.render();
    }
}
