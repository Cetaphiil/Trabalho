#ifndef ENTIDADE_H_P_P_
#define ENTIDADE_H_P_P_

#include "lib.hpp"

class Entidade{
    private:
        Vector2f posicao;
        Gerenciador_grafico loader;
    public:
        virtual void executar();
        void desenhar();
};

#endif