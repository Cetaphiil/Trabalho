#include <Gerenciador_grafico.hpp>

List *Gerenciador_grafico::add_sprite(List *list){
    List *n = (List *) malloc(sizeof(List));
    n->next = NULL;
    if (list == NULL)
        return n;
    List *aux = list;
    while (aux->next != NULL)
        aux = aux->next;
    aux->next = n;
    return list;
};

void Gerenciador_grafico::load_sprites(char **lista_nomes) {
    List *aux = NULL;
    aux = add_sprite(aux);
    sprite_list[0] = aux;
    aux->texture = new Texture;
    for (int i = 0; i < 10; i++) {
        add_sprite(sprite_list[0]);
        aux = aux->next;
        aux->texture = new Texture;
        aux->texture->loadFromFile(lista_nomes[i]);
    }
    aux->next = sprite_list[0];
};

void Gerenciador_grafico::loader(int quantidade_animacoes, char **lista_nomes) {
    sprite_list = (List **) malloc(quantidade_animacoes * sizeof(List *));

    for (int i = 0; i < quantidade_animacoes; i++)
        sprite_list[i] = NULL;

    //std::set < std::string, std::list <sf::Sprite> >

    load_sprites(lista_nomes);
};