//
// Created by David Rigby on 11/22/17.
//

#include "game.h"


// Game::Game() = default;

Game::Game(Player &p1, Player &p2) {

    Player1 = &p1;
    Player2 = &p2;

    gameState = GameState::TurnP1;
    srand((unsigned)time(NULL));
    rand();
    rand();


    for(int row = 0; row < BoardHeight; row++){
        for(int col = 0; col < BoardWidth; col++){
            gameBoard[row][col] = BoardField::Empty;
        }
    }


}



GameState Game::getState() {


    return this->gameState;


}

void Game::isWinner(int row, int col) {


    if(this->operator()(col,row) == BoardField::Empty){
        return;
    }
    bool NonFriendly = false;

    int counter = 1;
    int rowCounter = 1;
    // Down
    while(!NonFriendly){
       if(this->operator()(col, row+rowCounter) == this->operator()(col,row)) {
           counter++;
           rowCounter++;
       }else{
           NonFriendly = true;
       }
        if(counter == 4 && this->operator()(col,row) == BoardField::Player1){
            gameState = GameState::P1Won;
            return;
        }else if(counter == 4 && this->operator()(col,row) == BoardField::Player2){
            gameState = GameState::P2Won;
            return;
        }
    }

    counter = 1;
    int colCounter = 1;
    NonFriendly = false;
    // Right and left
    while(!NonFriendly){
        if(this->operator()(col+colCounter, row) == this->operator()(col,row)) {
            counter++;
            colCounter++;
        }else{
            NonFriendly = true;
        }
        if(counter == 4 && this->operator()(col,row) == BoardField::Player1){
            gameState = GameState::P1Won;
            return;
        }else if(counter == 4 && this->operator()(col,row) == BoardField::Player2){
            gameState = GameState::P2Won;
            return;
        }
    }

    colCounter = -1;
    NonFriendly = false;

    while(!NonFriendly){
        if(this->operator()(col+colCounter,row) == this->operator()(col,row)) {
            counter++;
            colCounter--;
        }else{
            NonFriendly = true;
        }
        if(counter == 4 && this->operator()(col,row) == BoardField::Player1){
            gameState = GameState::P1Won;
            return;
        }else if(counter == 4 && this->operator()(col,row) == BoardField::Player2){
            gameState = GameState::P2Won;
            return;
        }
    }

    counter = 1;
    colCounter = 1;
    rowCounter = 1;
    NonFriendly = false;
    // Diagonal down right
    while(!NonFriendly){
        if(this->operator()(col+colCounter,row+rowCounter) == this->operator()(col,row)) {
            counter++;
            colCounter++;
            rowCounter++;
        }else{
            NonFriendly = true;
        }
        if(counter == 4 && this->operator()(col,row) == BoardField::Player1){
            gameState = GameState::P1Won;
            return;
        }else if(counter == 4 && this->operator()(col,row) == BoardField::Player2){
            gameState = GameState::P2Won;
            return;
        }
    }

    colCounter = -1;
    rowCounter = -1;
    NonFriendly = false;
    // Diagaonal up left
    while(!NonFriendly){
        if(this->operator()(col+colCounter,row+rowCounter) == this->operator()(col,row)) {
            counter++;
            colCounter--;
            rowCounter--;
        }else{
            NonFriendly = true;
        }
        if(counter == 4 && this->operator()(col,row) == BoardField::Player1){
            gameState = GameState::P1Won;
            return;
        }else if(counter == 4 && this->operator()(col,row) == BoardField::Player2){
            gameState = GameState::P2Won;
            return;
        }
    }

    counter = 1;
    colCounter = -1;
    rowCounter = 1;
    NonFriendly = false;
    // Diagonal down left
    while(!NonFriendly){
        if(this->operator()(col+colCounter,row+rowCounter) == this->operator()(col,row)) {
            counter++;
            colCounter--;
            rowCounter++;
        }else{
            NonFriendly = true;
        }
        if(counter == 4 && this->operator()(col,row) == BoardField::Player1){
            gameState = GameState::P1Won;
            return;
        }else if(counter == 4 && this->operator()(col,row) == BoardField::Player2){
            gameState = GameState::P2Won;
            return;
        }
    }

    colCounter = 1;
    rowCounter = -1;
    NonFriendly = false;
    // Diagonal up right
    while(!NonFriendly){
        if(this->operator()(col+colCounter,row+rowCounter) == this->operator()(col,row)) {
            counter++;
            colCounter++;
            rowCounter--;
        }else{
            NonFriendly = true;
        }
        if(counter == 4 && this->operator()(col,row) == BoardField::Player1){
            gameState = GameState::P1Won;
            return;
        }else if(counter == 4 && this->operator()(col,row) == BoardField::Player2){
            gameState = GameState::P2Won;
            return;
        }
    }






}

bool Game::isDraw() {
    // Game game;
    for(int row = 0; row < BoardHeight; row++){
        for(int col = 0; col < BoardWidth; col++){
            if(this->operator()(col,row) == BoardField::Empty){
                return false;
            }

        }
    }

    return true;
}

void Game::makeMove(int col) {

    int row = 0;

    for(int i = 0; i < 6; i++)
    {
        if(gameBoard[i][col-1] != BoardField::Empty){
            row = i-1;
            break;
        }else if(i == BoardHeight-1){
            row = BoardHeight-1;
            break;
        }

    }

    if(gameState == GameState::TurnP1){
        gameBoard[row][col-1] = BoardField::Player1;
    }else if(gameState == GameState::TurnP2){
        gameBoard[row][col-1] = BoardField::Player2;
    }else if(isDraw()){
        gameState = GameState::Draw;
    }

    isWinner(row, col-1);


}


bool Game::isRunning() {

    return !(gameState == GameState::Draw || gameState == GameState::P1Won || gameState == GameState::P2Won);

}


BoardField Game::operator()(int x, int y) const {

    if (x < 7 && x >= 0 && y < 6 && y >= 0) {
        return gameBoard[y][x];
    } else {
        return BoardField::Empty;
    }


}


void Game::nextTurn() {

    int move;

    if(getState() == GameState::TurnP1)
    {
        move = Player1->getNextTurn(*this);


    }else if(getState() == GameState::TurnP2)
    {
        move = Player2->getNextTurn(*this);
        // gameState = GameState::TurnP1;



    }

    if(move <= 7 && move >= 1){

        makeMove(move);
        if(gameState == GameState::TurnP1){
            gameState = GameState::TurnP2;
        }else if(gameState == GameState::TurnP2){
            gameState = GameState::TurnP1;
        }


    }



}






