//
// Created by saulo on 14/08/2021.
//

#ifndef GRAFICHANDLER_HPP
#define GRAFICHANDLER_HPP
#include "lib.hpp"
#include <list>
using namespace sf;

class Graphics{
    public:
        static List* add_sprite(List* list);
        void load_Textures(const char **idle_file_names,List **sprite_list);

        Graphics();
};


#endif
