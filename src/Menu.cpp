#include <Menu.hpp>

Menu::Menu(){

};

void Menu::initMenu(Vector2f resolucao){
    back.loadFromFile("assets/background/Fundo.png");
    botoes.setSize(tamanhoBotoes);
    botoes.setFillColor(Color::Cyan);
    botoes.setOutlineThickness(2);
    startButton.setString("Start");
    mainFont.loadFromFile("assets/fonts/slant_regular.ttf");
    startButton.setFont(mainFont);
    botoes.setPosition(Vector2f((resolucao.x/4.5), (resolucao.y/1.5)));
    Vector2f startTextSize = {startButton.getLocalBounds().width/2.f, startButton.getLocalBounds().height/2.f};
    Vector2f botaoCentro = botoes.getPosition() + botoes.getSize()/2.f;
    startButton.setPosition(botaoCentro-startTextSize);
};

void Menu::updateMenu(RenderWindow *window){
    Vector2f buttonPosit = botoes.getPosition();
    Vector2f mousePosit = {(float) Mouse::getPosition(*window).x, (float) Mouse::getPosition(*window).y};
    FloatRect botao = {buttonPosit ,tamanhoBotoes};
    if(botao.contains(mousePosit)){
        botoes.setOutlineColor(Color::Red);
        startButton.setFillColor(Color::Red);
    }
    else{
        botoes.setOutlineColor(Color::White);
        startButton.setFillColor(Color::White);
    }
};

void Menu::renderMenu(RenderWindow *window){
    window->draw(botoes);
    window->draw(startButton);
};