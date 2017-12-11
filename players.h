//
// Created by David Rigby on 11/22/17.
//

#ifndef CONNECTFOUR_PLAYERS_H
#define CONNECTFOUR_PLAYERS_H


#include "game.h"
#include <iostream>

class Game;

class Player {

public:
    virtual int getNextTurn(Game &game) = 0;

};

class HumanPlayer : public Player {

public:
    int getNextTurn(Game &game);

};

class AiPlayer : public Player {

public:
    int getNextTurn(Game &game);

};


#endif //CONNECTFOUR_PLAYERS_H
