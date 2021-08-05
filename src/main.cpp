#include "main.h"


int main() {
    int a = 20;
    Event event;
    RenderWindow window (VideoMode (1280,720), "Teste", Style::Titlebar|Style::Close);

    Background back;
    Player player;

    back.loader();
    player.loader();

    while(window.isOpen()){
        while(window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }
        player.update(&window);

        window.clear(sf::Color::Black);
        back.show(&window);
        player.show(&window);
        window.display();
    }
}
