#include "main.hpp"
#include "Game.hpp"
#include "Menu.hpp"

int main() {
    Vector2i resolucao{1280, 720};
    RenderWindow window(VideoMode(resolucao.x, resolucao.y), "Jogo", Style::Titlebar | Style::Close);
    Menu mainMenu(resolucao);
    Event ev{};
    Engine engine;
    while(window.isOpen()){
        while (window.pollEvent(ev)) {
            window.clear();
            mainMenu.draw(&window);
                    switch (ev.type) {
                        case Event::KeyPressed:
                            switch (ev.key.code) {
                                case Keyboard::W:
                                    mainMenu.moveUp();
                                    break;
                                case Keyboard::S:
                                    mainMenu.moveDown();
                                    break;
                                case Keyboard::Return:
                                    switch (mainMenu.getSelected()) {
                                        case 0:
                                            while(window.isOpen()){

                                                engine.render(&window);

                                                engine.update(&window);

                                            }
                                            break;
                                        default:
                                            break;
                                    }
                                    break;
                                default:
                                    break;
                            }
                            break;
                        case Event::Closed:
                            window.close();
                            break;
                        default:
                            break;
                    }
            window.display();
        }
    }
}
