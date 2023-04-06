#include <iostream>
#include "tictactoeFuncts.h"


int main() {
    //create the board 2D array
    int** board = gameBoard();
    board[1][2] = 9;

    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; j++){
            std::cout << "This is [" << i << "][" << j << "]: " << board[i][j] << std::endl;
        }
    }




    deallocateGameBoard(board);
    return 0;
}
