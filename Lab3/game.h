//
// Created by David Rigby on 11/22/17.
//

#ifndef CONNECTFOUR_GAME_H
#define CONNECTFOUR_GAME_H

#include "players.h"
#include <ctime>

enum class GameState {TurnP1, TurnP2, P1Won, P2Won, Draw};

enum class BoardField {Empty, Player1, Player2};

class Player;
class HumanPlayer;
class AiPlayer;

class Game {

public:
    static const int BoardWidth = 7;
    static const int BoardHeight = 6;

    Game(Player &p1, Player &p2);
    GameState getState();
    bool isRunning();
    BoardField operator() (int x, int y) const;
    void nextTurn();


private:

    Game();
    GameState gameState;
    Player *Player1;
    Player *Player2;
    BoardField gameBoard[BoardHeight][BoardWidth];

    void isWinner(int x, int y);
    bool isDraw();
    void makeMove(int col);










};


#endif //CONNECTFOUR_GAME_H
