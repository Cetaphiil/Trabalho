#ifndef STDAFIX_H_P_P_
#define STDAFIX_H_P_P_

#define SNOW_PLATAFORM "../assets/sprites/Tiles/Lvl1/2.png"
#define FLOAT_SNOW_PLATAFORM "../assets/sprites/Tiles/Lvl1/15.png"
#define PLATFORM_GRAVEYARD_GRASS "../assets/sprites/Tiles/Lvl2/Tile1.png"
#define PLATAFORM_GRAVEYARD_FLOAT "../assets/sprites/Tiles/Lvl2/Tile2.png"
#define LANDMINE "../assets/sprites/LandMine/landmine.png"
#define SPIKE "../assets/sprites/Spikes/spike.png"
#define WATER "../assets/sprites/Tiles/Lvl1/17.png"
#define WALL "../assets/sprites/Tiles/Lvl1/5.png"
#define BACKLVL1 "../assets/background/Fundo.png"
#define BACKLVL2 "../assets/background/BG.png"

#define PLAT_HEIGHT 128
#define PLAT_WIDTH 128

#define LVL_HEIGHT 12
#define LVL_WIDTH 54

#define LVL1PATH "../assets/Maps/Fase1/lvl.txt"
#define LVL2PATH "../assets/Maps/Fase2/lvl.txt"

#include <SFML/Graphics.hpp>

#include <cstring>
#include <vector>
#include <List>
#include <fstream>
#include <iostream>
#include <math.h>

enum collidables{
	player = 'J',
	wrathInf = 'e',
    wraithInfR = 'E',
	wraithSup = 'w',
	wraithSupR = 'W',
	wraithQueen = 'q',
	wraithQueenR = 'Q',
	boss = 'B',
	landmine = 'l',
    landmineR = 'L',
	spike = 's',
    spikeR = 'S',
	platform = 'p',
    platformF = 'P',
    barrier = 'b',
	lvlEnd = 'd'
};

enum Kind{
    playerKind = 0, 
	enemyKind,
	bossKind,
	landmineKind,
	spikeKind,
	platformKind,
    barrierKind,
	waterKind
};

enum platTypeLvl1{
    SnowPlat = 0,
    FloatSnowPlat,
};

enum platTypeLvl2{
    GraveyardGrass = 0,
    FloatGraveyardGrass
};

struct List{
    sf::Texture *texture;
    List *next;
};


#endif