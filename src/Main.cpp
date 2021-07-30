
#include <lib.hpp>
int main(){
    
    Engine game;
    
    while(game.windowOpen()){
        
        game.update();
        
        game.render(); 
    }        
}