//
// Created by saulo on 14/08/2021.
//

#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include "Entity.hpp"

#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <list>

using namespace std;

class Map: public Entity{
    private:
        sf::Vector2i map[100][100];
        sf::Vector2i loadCounter;
        Texture textureList[3][3];
    public:
        Map(string tileDir);

        void initMap(string lvlDir);

        void loadTileMap(RenderWindow *window);

        Vector2f getPosition(){std::cout << "MAP CANNOT RETURN A POSITION" << std::endl; exit(1);}
};




#endif
