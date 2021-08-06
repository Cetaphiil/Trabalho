#ifndef GERENCIADOR_GRAFICO_H_P_P_
#define GERENCIADOR_GRAFICO_H_P_P_

#include "lib.hpp"

class Gerenciador_grafico{
    protected:

    List **sprite_list;
    
    public:
        Gerenciador_grafico(int quantidade_animacoes, char **lista_nomes, List *list);
    void loader(int quantidade_animacoes, char **lista_nomes);

    List *add_sprite(List *list);

    void load_sprites(char **lista_nomes);
};

#endif