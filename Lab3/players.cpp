//
// Created by David Rigby on 11/22/17.
//


#include <random>
#include "players.h"




int HumanPlayer::getNextTurn(Game &game) {

        // std::cout<<"Which Column do you want to put your piece? ";
        int Column;
        std::cin>>Column;

        return Column;


    }

int AiPlayer::getNextTurn(Game &game) {

        bool possibleCols[7];
        int colPick = rand() % 7;


        for(int i = 0; i < 7; i++){
            if(game(0,i)==BoardField::Empty){
                possibleCols[i] = true;
            }else{
                possibleCols[i] = false;
            }
        }

        while(!possibleCols[colPick]){
            colPick = rand() % 7;
        }

        return colPick;

}

