#ifndef STDAFIX_H_P_P_
#define STDAFIX_H_P_P_

#define SNOW_PLATAFORM "../assets/sprites/Tiles/Lvl1/2.png"
#define FLOAT_SNOW_PLATAFORM "../assets/sprites/Tiles/Lvl1/15.png"
#define WATER "../assets/sprites/Tiles/Lvl1/17.png"
#define PLATFORM_GRAVEYARD_GRASS "../assets/sprites/Tiles/Lvl2/Tile1.png"
#define PLATAFORM_GRAVEYARD_FLOAT "../assets/sprites/Tiles/Lvl2/Tile2.png"
#define SPIKE "../assets/sprites/Spikes/spike.png"

#define LVL1PATH "assets/Maps/Fase1/lvl.txt"

#include <SFML/Graphics.hpp>

#include <cstring>
#include <vector>
#include <List>
#include <fstream>
#include <iostream>

enum collidables
	{
		jogador,
		enemy,
		boss,
		orb,
		spike,
		platform,
		ar,
		noncollidable,
		standby
	};

enum state_id{
        mainMenu = 0,
        pauseMenu,
        newGameMenu,
        playing,
        paused,
        loading,
        scoreBoard
};

enum platType{
    SnowPlat = 0,
    FloatSnowPlat,
    GraveyardGrass,
    FloatGraveyardGrass
};

struct List{
    sf::Texture *texture;
    List *next;
};


#endif