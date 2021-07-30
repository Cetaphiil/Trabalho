#include "main.h"

bool isSpriteHover(FloatRect sprite, Vector2f mp){
    if (sprite.contains(mp)){
        return true;
    }
    return false;
}

int main() {
    int a = 20;
    Event event;
    RenderWindow window (VideoMode (1280,720), "Teste", Style::Titlebar|Style::Close);

    Background back;
    Player player;

    back.loader();
    player.loader();


    Vector2f mp;
    mp.x = Mouse::getPosition(window).x;
    mp.y = Mouse::getPosition(window).y;


    while(window.isOpen()){
        while(window.pollEvent(event)){
            if(event.type == Event::Closed){
                window.close();
            }
            /*if(isSpriteHover(back.sprite, mp)) {//this should check if the bool is true right?
                if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
                    std::cout << "Hello World" << std::endl;*/
            }

        player.update(&window);

        window.clear(sf::Color::Black);
        back.show(&window);
        player.show(&window);
        window.display();
    }
}
