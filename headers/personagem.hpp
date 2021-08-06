#ifndef PERSONAGEM_H_P_P_
#define PERSONAGEM_H_P_P_
#include "lib.hpp"

class Personagem : public Entidade{
    protected:
        int dano, vida, velocidade, aceleracao;
    public:
        Personagem();

};

#endif