#pragma once

#include "CollisionHandler.hpp"
#include "Entity.hpp"
#include "EntityList.hpp"
#include "EventHandler.hpp"
#include "GraphicHandler.hpp"
#include "Player.hpp"
#include "stdafix.hpp"

class Fase {
private:
    Graphics* pGrap;
    EventHandler* pEvent;
    EntityList* listE;
    Player *player1, *player2;
    sf::Vector2f mapSize;
    int reachEnd, lvlIsPlayable;

public:
    Fase(Player* p1, Player* p2, sf::Vector2f levelSize, EntityList* lE);
    virtual ~Fase();

    void execLvl(float dt);
    Player* getP1() const { return player1; };
    Player* getP2() const { return player2; };
    void setP1(Player* p1) { player1 = p1; };
    void setP2(Player* p2) { player2 = p2; };
    int lvlPlayable(){ return lvlIsPlayable; };
    void drawAllEntities();
    void centerViewAtPlayers();
    void addEntity(Entity* ent) { listE->add(ent); };
    void setEnd(int end) { reachEnd = end; };
};