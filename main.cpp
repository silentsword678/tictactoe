#include <iostream>
#include "tictactoeFuncts.h"


int main() {
    //create the board 2D array
    char** board = gameBoard();
//    board[1][2] = x;

    //show board
    std::cout << "Starting board" << std::endl;
    printGameBoard(board);

    Player player1 = createPlayer();
    Player player2 = createPlayer();

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
            //bad input
            while (badSelection(playerSelection, board)){
                std::cout << "Invalid Input!" << std::endl;
                std::cout << "Pick a number for the x: ";
                std::cin >> playerSelection[0];
                std::cout << "Pick a number for the y: ";
                std::cin >> playerSelection[1];
            }
            std::cout << "You picked: " << playerSelection[0] << ", " << playerSelection[1] << std::endl;

            //update board and selection
            board[playerSelection[0]][playerSelection[1]] = 'x';
            player1.selections[playerSelection[0]][playerSelection[1]] = 'x';

            //The better way to print the board
            printGameBoard(board);
            if (winnerFound(board)){
                std::cout << "Congrats " << player1.name << ". You WIN!!";
                break;
            }
        }
        else{
            std::cout << player2.name << ". It's your turn! Pick an available square!" << std::endl;
            std::cout << "Pick a number for the x: ";
            std::cin >> playerSelection[0];
            std::cout << "Pick a number for the y: ";
            std::cin >> playerSelection[1];
            //bad input
            while (badSelection(playerSelection, board)){
                std::cout << "Invalid Input!" << std::endl;
                std::cout << "Pick a number for the x: ";
                std::cin >> playerSelection[0];
                std::cout << "Pick a number for the y: ";
                std::cin >> playerSelection[1];
            }
            std::cout << "You picked: " << playerSelection[0] << ", " << playerSelection[1] << std::endl;

            //update board and selection
            board[playerSelection[0]][playerSelection[1]] = 'o';
            player2.selections[playerSelection[0]][playerSelection[1]] = 'o';

            //The better way to print the board
            printGameBoard(board);
            if (winnerFound(board)){
                std::cout << "Congrats " << player2.name << ". You WIN!!";
                break;
            }
        }


    }

    deallocateGameBoard(board);
    deallocatePlayer(player1);
    deallocatePlayer(player2);
    return 0;
}
