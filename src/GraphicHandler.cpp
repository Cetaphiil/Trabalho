#include <GraphicHandler.hpp>

Graphics* Graphics::instance = NULL;

Graphics* Graphics::getGraphics(){
    if(instance == NULL){
        instance = new Graphics();
    }
    return instance;
}

Graphics::Graphics(): resolution(WIDTH, HEIGHT), window(new RenderWindow(VideoMode(resolution.x, resolution.y), "NomeDoJOJ", Style::Titlebar | Style::Close)), back(){
    mainFont.loadFromFile("../assets/fonts/slant_regular.ttf");
}

Graphics::~Graphics(){
    delete instance;
}

List *Graphics::add_sprite(List* list){
    List *n = (List *) malloc(sizeof(List));
    n->next = nullptr;
    if (list == nullptr)
        return n;
    List *aux = list;
    while (aux->next != nullptr)
        aux = aux->next;
    aux->next = n;
    return list;
}

void Graphics::load_Textures(const char **file_names,List **sprite_list){
    List *aux = NULL;
    aux = add_sprite(aux);
    sprite_list[0] = aux;
    aux->texture = new sf::Texture;
    aux->texture->loadFromFile(file_names[0]);
    for (int i = 1; i < 10; i++) {
        add_sprite(sprite_list[0]);
        aux = aux->next;
        aux->texture = new sf::Texture;
        aux->texture->loadFromFile(file_names[i]);
    }
    aux->next = sprite_list[0];
}

RenderWindow* Graphics::getWindow() const{
    return window;
}

void Graphics::drawBackGround(){
    back.show(window);
}