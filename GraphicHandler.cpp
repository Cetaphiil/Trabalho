//
// Created by saulo on 14/08/2021.
//

#include <GraphicHandler.hpp>
Graphics::Graphics() {

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
