#pragma once

#include "StateMachine.hpp"
#include "MainMenu.hpp"
#include "PauseMenu.hpp"
#include "NewGameMenu.hpp"
#include "Playing.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "Fase.hpp"
#include "GraphicHandler.hpp"
#include "EventHandler.hpp"
#include "InputHandler.hpp"
#include "CollisionHandler.hpp"
#include "EntityList.hpp"
#include "stdafix.hpp"
#include "Spike.hpp"
#include "LandMine.hpp"

using namespace sf;

using namespace sm;

class Engine: public StateMachine
{
    private:
        Graphics* pGraphics;
        EventHandler* pEvents;
        InputHandler* pInputs;
        float deltatime = 0;
        int lvl;
        Player *p1, *p2;
        int playerAtGame;
        Fase* plvl;
        Collider *collider;
        EntityList listE;
        void initVariab();

    public:
        Engine();
        virtual ~Engine();

        void renderCharacters();

        void initLvl();

        Clock timer;
        
        void loadStates();

        void execState();
        
        void exec();

        void update();
        void render();

        Fase* getLvl() const;
        void setLvl(Fase *pL);

        Player *getP1();
        Player *getP2();

        Player* newPlayer();
        
        void setwhatLvl(int whatlvl);
        int getwhatLvl();

        void checkColision();

        void newProjectile();
        void newObject(int kind);
        void updateState(int statelabel);
};
