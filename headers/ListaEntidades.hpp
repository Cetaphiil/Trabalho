#ifndef LISTAENTIDADES_H_P_P_
#define LISTAENTIDADES_H_P_P_

#include <Game.hpp>
#include <objeto.h>

using namespace sf;
using namespace std;

typedef struct list{
    Texture *textura;
    list* next;
}List;

class Entidade{
    public:
    List **sprite_lista;
};

#endif