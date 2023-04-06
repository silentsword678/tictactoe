//
// Created by Marcus Barnes on 4/5/23.
//

#ifndef TICTACTOE_TICTACTOEFUNCTS_H
#define TICTACTOE_TICTACTOEFUNCTS_H

#include <iostream>

const int ROWS = 3;
const int COLS = 3;

int** gameBoard(){
    int** arr = new int*[ROWS];
    for (size_t i = 0; i < COLS; ++i){
        arr[i] = new int[COLS];
    }
    return arr;
}

void deallocateGameBoard(int** arr) {
    for (int i = 0; i < ROWS; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}

#endif //TICTACTOE_TICTACTOEFUNCTS_H
