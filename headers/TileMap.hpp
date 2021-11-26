//
// Created by saulo on 14/08/2021.
//

#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include "Entity.hpp"

#include <iostream>

using namespace std;

class Map: public Entity{
    private:
        sf::Vector2i map[10][10];
        sf::Vector2i loadCounter;
    public:
        Map(string tileDir = "");

        void initMap(string lvlDir = "");

        const Vector2i getMap(int i, int j);

        Vector2f getPosition(){ std::cout << "MAP CANNOT RETURN A POSITION" << std::endl; exit(1); }
};




#endif
