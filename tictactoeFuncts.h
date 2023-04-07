//
// Created by Marcus Barnes on 4/5/23.
//

#ifndef TICTACTOE_TICTACTOEFUNCTS_H
#define TICTACTOE_TICTACTOEFUNCTS_H

#include <iostream>
#include <utility>

const int ROWS = 3;
const int COLS = 3;

char** gameBoard(){
    char** arr = new char*[ROWS];
    for (size_t i = 0; i < COLS; ++i){
        arr[i] = new char[COLS];
    }
    return arr;
}

void deallocateGameBoard(char** arr) {
    for (int i = 0; i < ROWS; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}

struct Player {
    std::string name;
    char **selections{};
};

Player createPlayer(){
    Player p = Player{"", new char*[ROWS]};
    for (int i = 0; i < ROWS; ++i) {
        p.selections[i] = new char[COLS];
    }
    return p;
}

void deallocatePlayer(Player& player){
    for (int i = 0; i < ROWS; ++i) {
        delete[] player.selections[i];
    }
    delete[] player.selections;
}

void printGameBoard(char** gameBoard){

//    std::cout << "" << std::endl;
    std::cout << gameBoard[0][0] << "   " << gameBoard[0][1] << "   " << gameBoard[0][2] << std::endl;
    std::cout << "-|---|--" << std::endl;
    std::cout << gameBoard[1][0] << "   " << gameBoard[1][1] << "   " << gameBoard[1][2] << std::endl;
    std::cout << "-|---|--" << std::endl;
    std::cout << gameBoard[2][0] << "   " << gameBoard[2][1] << "   " << gameBoard[2][2] << std::endl;

}

#endif //TICTACTOE_TICTACTOEFUNCTS_H
