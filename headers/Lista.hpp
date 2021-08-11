//
// Created by Lucas Orlikoski on 09/08/2021.
//

#ifndef GAME_NEW_LISTA_HPP
#define GAME_NEW_LISTA_HPP
template <typename L>
class Lista{
public:
    Lista(){}
    ~Lista(){}
    no<L>* Ini{NULL};
    no<L>* Fim{NULL};
    void add(L info){
        no<L>* novo = new no<L>;
        novo->info = info;
        if(Fim == NULL){
            Fim = novo;
            Ini = novo;
        }
        else{
            Fim->p = novo;
            Fim = novo;
        }
    }
    template <typename N>
    class no{
    public:
        no* p{NULL};
        N info;
    };
};

#endif //GAME_NEW_LISTA_HPP
