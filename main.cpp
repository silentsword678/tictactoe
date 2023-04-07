#include <iostream>
#include "tictactoeFuncts.h"


int main() {
    //create the board 2D array
    char** board = gameBoard();
//    board[1][2] = x;

    //show board
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; j++){
            std::cout << "This is [" << i << "][" << j << "]: " << board[i][j] << std::endl;
        }
    }

    Player player1 = createPlayer();
    Player player2 = createPlayer();

    //How do we want to save their selection?

    int playerSelection[2] = {0,0};

    std::cout << "PLAYER 1: What is your name?" << std::endl;
    std::cin >> player1.name;
    std::cout << "Hello " << player1.name << "!" << std::endl;

    std::cout << "PLAYER 2: What is your name?" << std::endl;
    std::cin >> player2.name;
    std::cout << "Hello " << player2.name << "!" << std::endl;

    bool winner = false;

    //go until somebody wins, or it's after the last turn
    for(size_t turnCount = 1; turnCount < 10; ++turnCount){
        if(turnCount == 1 || (turnCount % 2) == 1){
            std::cout << player1.name << ". It's your turn! Pick an available square!" << std::endl;
            std::cout << "Pick a number for the x: ";
            std::cin >> playerSelection[0];
            std::cout << "Pick a number for the y: ";
            std::cin >> playerSelection[1];
            if (playerSelection[0] > 2 || playerSelection[1] > 2) {
                break;
            }
            std::cout << "You picked: " << playerSelection[0] << ", " << playerSelection[1] << std::endl;

            //update board and selection
            board[playerSelection[0]][playerSelection[1]] = 'x';
            player1.selections[playerSelection[0]][playerSelection[1]] = 'x';
            //show p1's board
            for (int i = 0; i < 3; ++i){
                for (int j = 0; j < 3; j++){
                    std::cout << "Player 1: This is [" << i << "][" << j << "]: " << player1.selections[i][j] << std::endl;
                }
            }

        }

        if((turnCount % 2) == 0){
            std::cout << player2.name << ". It's your turn! Pick an available square!" << std::endl;
            std::cout << "Pick a number for the x: ";
            std::cin >> playerSelection[0];
            std::cout << "Pick a number for the y: ";
            std::cin >> playerSelection[1];
            if (playerSelection[0] > 2 || playerSelection[1] > 2) {
                break;
            }
            std::cout << "You picked: " << playerSelection[0] << ", " << playerSelection[1] << std::endl;

            //update board and selection
            board[playerSelection[0]][playerSelection[1]] = 'o';
            player2.selections[playerSelection[0]][playerSelection[1]] = 'o';
            //show p2's board
            for (int i = 0; i < 3; ++i){
                for (int j = 0; j < 3; j++){
                    std::cout << "Player 2: This is [" << i << "][" << j << "]: " << player2.selections[i][j] << std::endl;
                }
            }

        }

        //the board
        for (int i = 0; i < 3; ++i){
            for (int j = 0; j < 3; j++){
                std::cout << "This is [" << i << "][" << j << "]: " << board[i][j] << std::endl;
            }
        }
        printGameBoard(board);

    }




    deallocateGameBoard(board);
    deallocatePlayer(player1);
    deallocatePlayer(player2);
    return 0;
}
