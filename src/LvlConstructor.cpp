#include "LvlConstructor.hpp"
#include "Game.hpp"

LvlConstructor::LvlConstructor(){
    lvl = NULL;
    pP2 = NULL;
    pP1 = NULL;
}

LvlConstructor::~LvlConstructor(){
    
}

void LvlConstructor::newPlat(Vector2f pos, int whatlvl, int type, int kind) {
    Platform* plat = new Platform(pos, whatlvl, type, kind);
    lvl->addEntity(plat);
}

void LvlConstructor::setP1(Vector2f posit) {
    lvl->getP1()->setPosition(posit);
}

void LvlConstructor::setP2(Vector2f posit) {
    if (lvl->getP2() != NULL)
        lvl->getP2()->setPosition(posit);
}

void LvlConstructor::newWraithInf(Vector2f posit, int kind){
    WraithInf* nE = new WraithInf(posit, kind);
    nE->setPlayer(pP1);
    lvl->addEntity(nE);
}

void LvlConstructor::newWraithSup(Vector2f posit, int kind){
    WraithSup* nE = new WraithSup(posit, kind);
    nE->setPlayer(pP1);
    lvl->addEntity(nE);
}

void LvlConstructor::newWraithQueen(Vector2f posit, int kind){
    WraithQueen* nE = new WraithQueen(posit, kind);
    nE->setPlayer(pP1);
    lvl->addEntity(nE);
}

void LvlConstructor::newSpike(Vector2f posit, int kind){
    Spike* nS = new Spike(posit, kind);
    lvl->addEntity(nS);
}

void LvlConstructor::newLandMine(Vector2f posit, int kind){
    LandMine* nLM = new LandMine(posit, kind);
    lvl->addEntity(nLM);
}

void LvlConstructor::newWall(Vector2f posit, int kind){
    Wall* nW = new Wall(posit, kind);
    lvl->addEntity(nW);
}

Fase* LvlConstructor::levelBuilder(Player* p1, Player* p2, int whatlvl, EntityList* listE){

    this->pListE = listE;

    pP1 = p1;
    pP2 = p2;

    char level[(int) LVL_HEIGHT][(int) LVL_WIDTH];
    srand(time(NULL));
    ifstream file;

    if (whatlvl == 1) {
        file.open(LVL1PATH);
        lvl = new Fase(pP1, pP2, {LVL_WIDTH * platSize.x, LVL_HEIGHT * platSize.y}, pListE);
    } else if(whatlvl == 2){
        file.open(LVL2PATH);
        lvl = new Fase(pP1, pP2, {LVL_WIDTH * platSize.x, LVL_HEIGHT * platSize.y}, pListE);
    }

    file >> level[0][0];
    while (!file.eof()) {
        file.ignore();
        for (int i = 0; i < LVL_HEIGHT; i++) {
            for (int j = 0; j < LVL_WIDTH; j++) {
                if (i  >= 0 || j >= 0) {
                    file >> level[i][j];
                }
                if (level[i][j] == collidables::platform) {
                    newPlat(Vector2f(j * PLAT_WIDTH, i * (PLAT_HEIGHT)), whatlvl, 0, Kind::platformKind);
                }else if (level[i][j] == collidables::platformF) {
                    newPlat(Vector2f(j * PLAT_WIDTH, i * PLAT_HEIGHT), whatlvl, 1, Kind::platformKind);
                } else if (level[i][j] == collidables::player) {
                    setP1(Vector2f(j * PLAT_WIDTH, i * PLAT_HEIGHT));
                } else if (level[i][j] == collidables::player && pP2 != NULL) {
                    setP2(Vector2f(j * PLAT_WIDTH, i * PLAT_HEIGHT));
                } else if (level[i][j] == collidables::wrathInf) {
                    newWraithInf(Vector2f((j * PLAT_WIDTH), (i * PLAT_HEIGHT)), Kind::enemyKind);
                } else if (level[i][j] == collidables::wraithSup) {
                    newWraithSup(Vector2f((j * PLAT_WIDTH), (i * PLAT_HEIGHT)), Kind::enemyKind);
                } else if (level[i][j] == collidables::wraithQueen) {
                    newWraithQueen(Vector2f((j * PLAT_WIDTH), (i * PLAT_HEIGHT)), Kind::enemyKind);
                } else if (level[i][j] == collidables::barrier) {
                    newWall(Vector2f(j * PLAT_WIDTH, i * PLAT_HEIGHT), Kind::barrierKind);
                }else if (level[i][j] == collidables::spike) {
                    newSpike(Vector2f(j *PLAT_WIDTH , i * PLAT_HEIGHT), Kind::spikeKind);
                } else if (level[i][j] == collidables::landmine) {
                    newLandMine(Vector2f(j *PLAT_WIDTH , i * PLAT_HEIGHT), Kind::landmineKind);
                } else if (level[i][j] == collidables::wraithInfR) {
                    int randNum = rand() % 10;
                    if (randNum == 5 || randNum == 9);
                        newWraithInf(Vector2f(j *PLAT_WIDTH , i * PLAT_HEIGHT), Kind::enemyKind);
                } else if (level[i][j] == collidables::spikeR) {
                    int randNum = rand() % 10;
                    if (randNum == 2 || randNum == 7)
                        newSpike(Vector2f(j *PLAT_WIDTH , i * PLAT_HEIGHT), Kind::spikeKind);
                } else if (level[i][j] == collidables::landmineR) {
                    int randNum = rand() % 10;
                    if (randNum == 3 || randNum == 8)
                        newLandMine(Vector2f(j * PLAT_WIDTH, i * PLAT_HEIGHT), Kind::landmineKind);
                } 
            }
        }
    }
    file.close();
    return lvl;
}