#ifndef STDAFIX_H_P_P_
#define STDAFIX_H_P_P_

#include <SFML/Graphics.hpp>

#include <string>
#include <vector>
#include <List>
#include <fstream>
#include <iostream>

enum StateID{
        mainMenu = 0,
        NewGame,
        Playing,
        Paused,
        Load,
        ScoreBoard
    };

struct List{
    sf::Texture *texture;
    List *next;
};


#endif