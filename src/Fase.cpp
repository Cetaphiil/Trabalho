#include "Fase.hpp"
#include "Game.hpp"

Fase::Fase(Player* p1, Player* p2, sf::Vector2f levelSize, EntityList* lE) {
    player1 = p1;
    player2 = p2;
    mapSize = levelSize;
    reachEnd = 1000;
    listE = lE;
    pGrap = Graphics::getGraphics();
    pEvent = EventHandler::getInstance();
};

Fase::~Fase() {
    if (player1) {
        listE->remove(player1);
        player1 = NULL;
    }
    if (player2) {
        listE->remove(player2);
        player2 = NULL;
    }
    delete (listE);
};

void Fase::execLvl(float dt) {

    if (player1->getShowing()) {
        if (player2 != NULL && !player2->getShowing())
            lvlIsPlayable = 0;

        listE->update(dt);

        if (player1->getPosition().x >= reachEnd) {
            if (player2) {
                if (player2->getPosition().x >= reachEnd) {
                    lvlIsPlayable = -1;
                } else
                    lvlIsPlayable = 1;
            } else
                lvlIsPlayable = -1;
        }
    } else{
        lvlIsPlayable = 0;
    }

};

void Fase::drawAllEntities() {
    centerViewAtPlayers();

    pGrap->drawBackGround();

    for (int i = 0; i < listE->getLength(); i++) {
        if ((*listE)[i]->getShowing())
            (*listE)[i]->show(pGrap->getWindow());
    }
};

void Fase::centerViewAtPlayers() {
    sf::Vector2f viewPosition, backpos;

    if (player2 == NULL) {
        viewPosition = player1->getPosition();
    } else {
        viewPosition = ((player1->getPosition() * float (1.2)) + player2->getPosition() * float (1.2)) / 2.0f;
    }

    if(player2 == NULL){
        backpos = Vector2f{player1->getPosition().x - 900.f, player1->getPosition().y - 446.5f};
    }

    pGrap->setViewPosition(viewPosition);
    pGrap->resetBackposit(backpos);
};