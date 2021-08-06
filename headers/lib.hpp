#ifndef LIB_H_P_P_
#define LIB_H_P_P_

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window.hpp>

using namespace sf;
using namespace std;

typedef struct list{

    Texture *texture;
    list *next;

}List;

typedef struct lista_diretorio{

    List *lista;
    lista_diretorio *next;

}Lista_diretorio;

#include <stdio.h>
#include <iostream>
#include <ostream>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <iostream>

#include "personagem.hpp"
#include "Game.hpp"
#include "Menu.hpp"
#include "Enemy.hpp"
#include "Entidade.hpp"
#include "Player.h"
#include "Gerenciador_grafico.hpp"

#endif